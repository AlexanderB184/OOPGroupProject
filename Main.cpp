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
  srand(time(NULL));
  // Splash Screen
  cout << "Press Enter to Begin" << endl;
  cin;
  cout << "Do you want to Load a game or Start a new game?" << endl;
  string option = "new";
  bool isValid = false;
  while (!isValid) {
    cin >> option;
    if (option == "new" || option == "load") {
      isValid = true;
    } else {
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
    Players[1] = new ComputerController(game[0].PossibleCharacters[rand()%game[0].nPossibleCharacters],nullptr,0);
    Battle battle = Battle(Players, 0);
    battle.initBattle();
    bool winner = battle.runBattle();
    return 0; 
}
