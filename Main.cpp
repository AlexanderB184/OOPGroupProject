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
#include "Move.h"
#include "Attack_Move.h"
#include "Heal_Move.h"


int main(void) { 
    //Splash Screen
    cout << "Press Enter to Begin" << endl;
    cin;
    cout << "Do you want to Load a game or Start a new game?" << endl;
    string option = "new";
    bool isValid = false;
    while (!isValid) {
      cin >> option;
      if (option == "new" || option == "load") {
        isValid = true;
      }
      else {
        cout << "Please select a valid option" << endl;
      }
    }

    GameSave * game = new GameSave();
    Controller** Players = new Controller*[2];

    if (option == "new") {
      Players[0] = new HumanController(game[0].selectCharacter(), nullptr, 0);

    } else {
      // Blank
    }
    Move** Moves = new Move* [3];
    Moves[0] = new Attack_Move("Slap", 1000, 30, 80);
    Moves[1] = new Attack_Move("Body Slam", 5, 50, 20);
    Moves[2] = new Heal_Move("Inject Substances", 6, 30, 5);
    Players[1] = new ComputerController( new Character("Enemy",100,50,50,50,50,Moves,3),nullptr,0);
    Battle battle = Battle(Players, 0);
    battle.initBattle();
    bool winner = battle.runBattle();
    return 0; 
}
