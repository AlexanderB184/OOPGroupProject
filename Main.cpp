// General Includes
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

using namespace std;

// Our Files
#include "Attack_Move.h"
#include "Battle.h"
#include "Character.h"
#include "ComputerController.h"
#include "Controller.h"
#include "GameSave.h"
#include "Heal_Move.h"
#include "HumanController.h"
#include "Move.h"
#include "Status.h"
#include "UI.h"

int main(void) {
  srand(time(NULL));

  Status** newStatus = new Status*[1];
  newStatus[0] = new BurnEffect();
  newStatus[0][0].damageRate;
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

  GameSave* game = new GameSave();
  Controller** Players = new Controller*[2];

  if (option == "new") {
    Players[0] = new HumanController(game[0].selectCharacter(), nullptr, 0);

  } else {
    // Blank
  }
  Players[1] = new ComputerController(
      game[0].PossibleCharacters[rand() % game[0].nPossibleCharacters], nullptr,
      0);
  Battle battle = Battle(Players, 0);
  battle.initBattle();
  bool winner = battle.runBattle();
  return 0;
}
