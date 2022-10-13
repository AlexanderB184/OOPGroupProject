//General Includes
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Our Files
#include "Character.h"
#include "Controller.h"
#include "ComputerController.h"
#include "HumanController.h"
#include "Status.h"
#include "Battle.h"
#include "GameSave.h"
#include "UI.h"

int main(void) { 
    //Splash Screen

    string option = "";
    GameSave Game = GameSave();
    UI ui = UI();
    // Ask Character if they want to load or create new
    if (option == "load") {
        //Ask for game save
        string filename = "";
        // If it is valid
        Game.loadFromFile(filename);

    } else if (option == "new") {
        //Ask player for character
        Game.Character1 = ui.selectCharacter();
        //Ask player to select items
        Game.Players[0][0].addItem(&ui.selectItem());

    }

    if (option == "load" || option == "new") {
      Game.OngoingBattle.initBattle();
      bool winner;
      winner = Game.OngoingBattle.runBattle();
    }
    return 0; 
}
