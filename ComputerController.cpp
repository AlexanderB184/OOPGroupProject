#include "ComputerController.h"

#include <string>

using namespace std;

Action* ComputerController::getAction() {
  // return a random action from the list of possible options
  return actionOptions[rand() % numberOfOptions];
};

ComputerController::ComputerController() {
  numberOfItems = 0;
  inventory = nullptr;
  numberOfOptions = 0;
  actionOptions = nullptr;
  character = nullptr;
};

ComputerController::ComputerController(Character* _character, Item* _inventory,
                                       int _numberOfItems) {
  numberOfItems = _numberOfItems;
  inventory = _inventory;
  numberOfOptions = 0;
  actionOptions = nullptr;
  character = _character;
};

ComputerController::~ComputerController() {
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