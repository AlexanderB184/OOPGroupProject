#include "HumanController.h"

#include <string>
#include <iostream>

using namespace std;

Action* HumanController::getAction() { 
    bool isValidOption = false;
    string userInput;
    while (!isValidOption) {
      cout << "Select an Option" << endl;
      for (int iOption = 0; iOption < numberOfOptions; iOption++){
        cout << iOption << ": " << actionOptions[iOption][0].name << ": " << actionOptions[iOption][0].description << endl;
      }
      cin >> userInput;
      cout << endl;
      for (int iOption = 0; iOption < numberOfOptions; iOption++) {
        if (userInput == actionOptions[iOption][0].name) {
          return actionOptions[iOption];
        }
        }
      cout << "Invalid Option, try again" << endl;
    }
};

HumanController::HumanController() { 
    numberOfItems = 0;
    inventory = nullptr;
    numberOfOptions = 0;
    actionOptions = nullptr;
    character = nullptr;
};

HumanController::HumanController(Character* _character, Item* _inventory, int _numberOfItems){
    numberOfItems = _numberOfItems;
    inventory = _inventory;
    numberOfOptions = 0;
    actionOptions = nullptr;
    character = _character;
};

HumanController::~HumanController(){
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