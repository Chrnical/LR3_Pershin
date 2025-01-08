#include "Field.h"


Field::Field(int width, int height){
    this->width = width;
    this->height = height;
    this->cells = std::vector <std::vector <Cell> > (width);
    for(int i = 0; i < width; i++){
        this->cells[i] = std::vector <Cell> (height);
    }
}

int Field::getWidth() const {
    return this->width;
}

int Field::getHeight() const {
    return this->height;
}

bool Field::placeShip(Ship* ship, int x, int y){
    if(x < 0 || y < 0 || x >= this->width || y >= this->height){
        return false;
    }
    if(ship->getOrientation() == Ship::Orientation::horizontal){
        if(x + ship->getLength() > this->width){
            return false;
        }
        for(int i = x; i < x + ship->getLength(); i++){
            if(!this->ifEmpty(i, y)){
                return false;
            }
        }
        for(int i = 0; i < ship->getLength(); i++){
            this->cells[x + i][y].putSegment(ship, i);
        }
    }else{
        if(y + ship->getLength() > this->width){
            return false;
        }
        for(int j = y; j < y + ship->getLength(); j++){
            if(!this->ifEmpty(x, j)){
                return false;
            }
        }
        for(int j = 0; j < ship->getLength(); j++){
            this->cells[x][y + j].putSegment(ship, j);
        }
    }
    return true;
}

bool Field::shoot(int x, int y){
    if(x < 0 || y < 0 || x >= width || y >= height){
        throw OutOfBoundsException();
    }
    this->cells[x][y].shootCell(doubleDamage);
    doubleDamage = false;
    return true;
}

bool Field::ifEmpty(int x, int y){
    if(cells[x][y].checkSegment()){
        return false;
    }
    if(x - 1 >= 0 && cells[x-1][y].checkSegment()){
        return false;
    }
    if(y - 1 >= 0 && cells[x][y-1].checkSegment()){
        return false;
    }
    if(x + 1 < width && cells[x+1][y].checkSegment()){
        return false;
    }
    if(y + 1 < height && cells[x][y+1].checkSegment()){
        return false;
    }
    return true;
}

Field::Field(Field& source){
    this->width = source.getWidth();
    this->height = source.getHeight();
    this->cells = std::vector <std::vector <Cell> > (width);
    for(int i = 0; i < width; i++){
        this->cells[i] = std::vector <Cell> (height);
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(source.getCell(i,j).getSegment() == 0){
                Ship* newShip = new Ship(source.getCell(i,j).getShip().getLength(), source.getCell(i,j).getShip().getOrientation());
                this->placeShip(newShip, i, j);
            }
        }
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            this->cells[i][j] = source.cells[i][j];
        }
    }
}

void Field::printField(){
    for(int i = 0; i < width; i++){
        std::cout << "==";
    }
    std::cout << "=\n";
    for(int j = 0; j < height; j++){
        for(int i = 0; i < width; i++){
            std::cout << "|";
            this->cells[i][j].printCell();
        }
        std::cout << "|\n";
        for(int i = 0; i < width; i++){
            std::cout << "==";
        }
        std::cout << "=\n";
    }
    std::cout << "\n";
}

Cell& Field::getCell(int x, int y){
    return this->cells[x][y];
}

Field &Field::operator=(Field& source) {
    this->width = source.getWidth();
    this->height = source.getHeight();
    this->cells = std::vector <std::vector <Cell> > (width);
    for(int i = 0; i < width; i++){
        this->cells[i] = std::vector <Cell> (height);
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(source.getCell(i,j).getSegment() == 0){
                Ship* newShip = new Ship(source.getCell(i,j).getShip().getLength(), source.getCell(i,j).getShip().getOrientation());
                this->placeShip(newShip, i, j);
            }
        }
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            this->cells[i][j] = source.cells[i][j];
        }
    }
    return *this;
}


Field::Field(Field &&source) {
    this->width = source.width;
    this->height = source.height;
    this->cells = std::move(source.cells);
    source.width = 0;
    source.height = 0;
}


Field &Field::operator=(Field &&source) {
    if(this == &source){
        return *this;
    }
    this->width = source.width;
    this->height = source.height;
    this->cells = std::move(source.cells);
    source.width = 0;
    source.height = 0;
    return *this;
}

void Field::setDoubleDamage(bool a) {
    doubleDamage = a;
}

bool Field::getDoubleDamage() {
    return doubleDamage;
}

void Field::show() {
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(cells[i][j].checkSegment()) {
                cells[i][j].setStatus(Cell::Status::ship);
            }else{
                cells[i][j].setStatus(Cell::Status::empty);
            }
        }
    }
}

void Field::outShips(std::ostream &buffer) {
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(cells[i][j].getSegment() == 0){
                buffer << i << " " << j << " ";
                cells[i][j].getShip().outShip(buffer);
            }
        }
    }
}

void Field::outCells(std::ostream &buffer) {
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            buffer << (int) cells[i][j].getStatus() << " ";
        }
    }
}
