#ifndef GAMESAVE_H
#define GAMESAVE_H

#include "Battle.h"
#include "Controller.h"
#include "ComputerController.h"
#include "HumanController.h"
#include "Character.h"

#include <string>
#include <iostream>

class GameSave {
    public:
     Battle OngoingBattle;
     HumanController Player1;
     ComputerController Player2;
     Character Character1;
     Character Character2;

     GameSave();
     ~GameSave();

     bool loadFromFile(string filename);
     bool saveToFile(string filename);
};

#endif