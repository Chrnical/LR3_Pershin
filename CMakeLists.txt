cmake_minimum_required(VERSION 3.22)
project(lr1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lr1 main.cpp
        Ship.cpp Ship.h
        Cell.cpp Cell.h
        Field.cpp Field.h
        ShipManager.cpp ShipManager.h
        Spell.cpp Spell.h
        Input.cpp Input.h
        DoubleDamage.cpp DoubleDamage.h
        Scan.cpp Scan.h
        Barrage.cpp Barrage.h
        SpellManager.cpp SpellManager.h
        GameException.h GameExceptions.h
        Game.cpp Game.h
        GameState.cpp GameState.h
        )
