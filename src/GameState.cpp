//
// Created by Артем on 28.11.2024.
//

#include "GameState.h"

bool GameState::loss() {
    return playerShipManager->countDestroyed() == playerShipManager->count();
}

bool GameState::win() {
    return botShipManager->countDestroyed() == botShipManager->count();
}

void GameState::generateBot() {
    botField = new Field(fieldWidth, fieldHeight);
    botShipManager = new ShipManager();
    input->setField(botField);
    for(short i = 1; i <= playerShipManager->count() / 2 + 1; i++){
        if(rand() % 2) {
            botShipManager->addShip(i, Ship::Orientation::vertical);
        }else{
            botShipManager->addShip(i);
        }
        while(!botField->placeShip(&botShipManager->getShip(i - 1), rand() % fieldWidth, rand() % fieldHeight)){}
    }
}

void GameState::shipPlacementPhase() {
    short length;
    char orientation;
    int x,y;
    int i = 0;
    std::cout << "Enter field dimensions (<width> <height>):";
    std::cin >> fieldWidth >> fieldHeight;
    playerField = new Field(fieldWidth,fieldHeight);
    playerShipManager = new ShipManager();
    spellManager = new SpellManager();
    while(true) {
        std::cout << "Enter ship length:";
        std::cin >> length;
        if(length == 0){
            break;
        }
        std::cout << "Enter ship orientation (V/H):";
        std::cin >> orientation;
        if(orientation == 'V'){
            playerShipManager->addShip(length, Ship::Orientation::vertical);
        }else{
            playerShipManager->addShip(length, Ship::Orientation::horizontal);
        }
        std::cout << "Enter coordinates to place the ship on (<x> <y>):";
        std::cin >> x >> y;
        playerField->placeShip(&(playerShipManager->getShip(i)), x, y);
        playerField->show();
        playerField->printField();
        i++;
    }
}

void GameState::spellCastPhase() {
    std::cout << "Spells left: " << spellManager->countSpells() << "\n";
    std::cout << "Do you want to cast a spell? (Y/N):";
    char player;
    std::cin >> player;
    if(player == 'Y'){
        spellManager->castSpell(*input);
        if(botShipManager->checkDestroyed()){
            std::cout << "Ship destroyed! New spell added.\n";
            spellManager->addSpell();
        }
    }
}

void GameState::shootCellPhase() {
    int x,y;
    std::cout << "Choose a cell to shoot (<x> <y>):";
    std::cin >> x >> y;
    botField->shoot(x,y);
    if(botShipManager->checkDestroyed()){
        std::cout << "Ship destroyed! New spell added.\n";
        spellManager->addSpell();
    }
}

void GameState::botTurnPhase() {
    playerField->shoot(rand() % fieldWidth, rand() % fieldHeight);
}

void GameState::printFields() {
    std::cout << "Player:\n";
    playerField->printField();
    std::cout << "Bot\n";
    botField->printField();
}

GameState::GameState() {
    input = new Input();
}

Field &GameState::getPlayerField() const {
    return *playerField;
}

ShipManager &GameState::getPlayerShipManager() const {
    return *playerShipManager;
}

ShipManager &GameState::getBotShipManager() const {
    return *botShipManager;
}

Field &GameState::getBotField() const {
    return *botField;
}

SpellManager &GameState::getSpellManager() const {
    return *spellManager;
}

GameState::GameState(int w, int h) {
    fieldHeight = h;
    fieldWidth = w;
    playerShipManager = new ShipManager();
    botShipManager = new ShipManager();
    playerField = new Field(fieldWidth, fieldHeight);
    botField = new Field(fieldWidth, fieldHeight);
    std::queue <Spell*> queue = {};
    spellManager = new SpellManager(queue);
    input = new Input(botField);
}


void GameState::savePhase() const {
    std::cout << "Do you want to save? (Y/N):";
    char player;
    std::cin >> player;
    if(player == 'Y'){
        std::cout << *this << std::endl;
    }
}

void GameState::loadPhase() {
    std::cout << "Do you want to load? (Y/N):";
    char player;
    std::cin >> player;
    if(player == 'Y'){
        std::cin >> *this;
    }
}


std::ostream& operator<<(std::ostream& os, const GameState& gameState) {
    std::ostringstream buffer;
    buffer << gameState.getPlayerField().getWidth() << " " << gameState.getPlayerField().getHeight() << " ";
    buffer << gameState.getPlayerField().getDoubleDamage() << " ";
    buffer << gameState.getPlayerShipManager().count() << " ";
    gameState.getPlayerField().outShips(buffer);
    gameState.getPlayerField().outCells(buffer);
    buffer << gameState.getBotShipManager().count() << " ";
    gameState.getBotField().outShips(buffer);
    gameState.getBotField().outCells(buffer);
    buffer << gameState.getSpellManager().countSpells() << " ";
    std::queue<Spell*> queue (gameState.getSpellManager().getQueue());
    while(!queue.empty()){
        buffer << queue.front()->getSpellId() << " ";
        queue.pop();
    }
    os << buffer.str();
    return os;
}

std::istream& operator>>(std::istream& is, GameState& gameState) {
    int w, h;
    int x, y;
    is >> w >> h;
    GameState newGameState = GameState(w,h);
    bool dd;
    is >> dd;
    newGameState.getBotField().setDoubleDamage(dd);
    short shipLength;
    int shipOrientation;
    int segmentState;
    int cellStatus;
    int shipCount;
    is >> shipCount;
    for(int i = 0; i < shipCount; i++){
        is >> x;
        is >> y;
        is >> shipLength;
        is >> shipOrientation;
        newGameState.getPlayerShipManager().addShip(shipLength, Ship::Orientation(shipOrientation));
        newGameState.getPlayerField().placeShip(&newGameState.getPlayerShipManager().getShip(i), x, y);
        for(short segment = 0; segment < shipLength; segment++){
            is >> segmentState;
            newGameState.getPlayerShipManager().getShip(i).setSegmentState(segment, Ship::SegmentState(segmentState));
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            is >> cellStatus;
            newGameState.getPlayerField().getCell(i,j).setStatus(Cell::Status(cellStatus));
        }
    }
    is >> shipCount;
    for(int i = 0; i < shipCount; i++){
        is >> x >> y;
        is >> shipLength;
        is >> shipOrientation;
        newGameState.getBotShipManager().addShip(shipLength, Ship::Orientation(shipOrientation));
        newGameState.getBotField().placeShip(&newGameState.getBotShipManager().getShip(i), x, y);
        for(short segment = 0; segment < shipLength; segment++){
            is >> segmentState;
            newGameState.getBotShipManager().getShip(i).setSegmentState(segment, Ship::SegmentState(segmentState));
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            is >> cellStatus;
            newGameState.getBotField().getCell(i,j).setStatus(Cell::Status(cellStatus));
        }
    }
    int spellCount;
    short spellId;
    is >> spellCount;
    std::vector <Spell*> allSpells = {new Scan, new Barrage, new DoubleDamage};
    std::queue <Spell*> queue;
    for(int i = 0; i < spellCount; i++){
        is >> spellId;
        queue.push(allSpells[spellId]);
    }
    newGameState.getSpellManager() = SpellManager(queue);
    gameState = newGameState;
    return is;
}