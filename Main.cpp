// General Includes
#include <stdlib.h>
#include <time.h>

#include <fstream>
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
#include "UseItem.h"
#include "Item.h"

int main(void) {
  srand(time(NULL));
  // Splash Screen
  string option = "new";
  cout << "Enter Any Character to Begin" << endl;
  cin >> option;
  cout << "Do you want to Load a game or Start a new game? ('new' or 'load')" << endl;
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
    Players[0] = new HumanController(
        game[0].selectCharacter(),
        game[0].PossibleItems[rand() % game[0].nPossibleItems], 1);

  } else if (option == "load") {
    cout << "What save do you want to load? (Enter save name)" << endl;
    string filename;
    cin >> filename;
    Players[0] = new HumanController(
        game[0].loadFromFile(filename),
        game[0].PossibleItems[rand() % game[0].nPossibleItems][0].clone(), 1);
  }

  Players[1] = new ComputerController(
      game[0].PossibleCharacters[rand() % game[0].nPossibleCharacters],
      game[0].PossibleItems[rand() % game[0].nPossibleItems][0].clone(), 1);
  bool endRematch = false;
  Battle battle = Battle(Players, 0);
  while (!endRematch) {
    battle.initBattle();
    bool winner = battle.runBattle();
    if (winner) {
      cout << endl << "Congratulations, you won!" << endl;
    } else {
      cout << "You lost." << endl;
    }
    cout << "Would you like to save your progress? ('y' or 'n')" << endl;
    string option = "";
    cin >> option;
    if (option == "Y" || option == "y" || option == "yes") {
      //cout << "Would you like to save your progress? ('y' or 'n')" << endl;
      string filename;
      cout << "Name your save" << endl;
      cin >> filename;
      game[0].saveToFile(filename, Players[0][0].character[0].Name);
    }

    if (winner) {
      cout << "Would you like to start a new battle? ('y' or 'n')" << endl;
      string option;
      cin >> option;
      if (option == "Y" || option == "y" || option == "yes") {
        delete Players[1];
        Players[1] = new ComputerController(
            game[0].PossibleCharacters[rand() % game[0].nPossibleCharacters],
            game[0].PossibleItems[rand() % game[0].nPossibleItems][0].clone(), 1);
      } else {
        endRematch = true;
      }
    } else {
      cout << "Would you like a rematch? ('y' or 'n')" << endl;
      string option;
      cin >> option;
      if (option == "N" || option == "n" || option == "no") {
        cout << "Would you like to start a new battle? ('y' or 'n')" << endl;
        cin >> option;
        if (option == "Y" || option == "y" || option == "yes") {
          delete Players[1];
          Players[1] = new ComputerController(
              game[0].PossibleCharacters[rand() % game[0].nPossibleCharacters],
              nullptr, 0);
        } else {
          endRematch = true;
        }
      } else if (option == "Y" || option == "y" || option == "yes") {
        endRematch = false;
      }
    }
  }
  return 0;
}
