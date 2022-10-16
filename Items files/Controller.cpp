#include "Controller.h"

#include <string>

using namespace std;

Controller::Controller() { 
    numberOfItems = 0;
    inventory = nullptr;
    numberOfOptions = 0;
    actionOptions = nullptr;
    character = nullptr;
};

Controller::Controller(Character* _character, Item* _inventory, int _numberOfItems){
    numberOfItems = _numberOfItems;
    inventory = _inventory;
    numberOfOptions = 0;
    actionOptions = nullptr;
    character = _character;
};

Controller::~Controller(){
    if (actionOptions != nullptr) {
    
      for (int iAction = 0; iAction < numberOfOptions; iAction++) {
        delete actionOptions[iAction];
      }
      delete actionOptions;
    }
    
    if (character != nullptr) {
      delete character;
    }
    if (inventory != nullptr) {
      delete inventory;
    }
};

void Controller::generateOptions() {

  //free old options array
  //it is only neccessary to delete the array of pointers and not the objects they point to.
  delete actionOptions;
  actionOptions = nullptr;

  //Calculate the number of options availavle to a character
  numberOfOptions = numberOfItems + character->numberOfMoves;

  actionOptions = new Action*[numberOfOptions];

  int iOption = 0;
  
  //add characters Moveset to Action Options
  for (int iMove = 0; iMove < character->numberOfMoves; iMove++) {
    actionOptions[iOption] = character[0].Moveset[iMove];
    iOption++;
  }

  //add item actions to Action Options
  for (int iItem = 0; iItem < numberOfItems; iItem++) {
    actionOptions[iOption] = inventory[iItem].action;
    iOption++;
  }

}