#include "Controller.h"

#include <string>

#include "Action.h"
#include "Item.h"
#include "Move.h"

using namespace std;

void Controller::generateOptions() {
  // free old options array
  // it is only neccessary to delete the array of pointers and not the objects
  // they point to.
  delete actionOptions;
  actionOptions = nullptr;

  // Calculate the number of options availavle to a character

  actionOptions = new Action*[numberOfOptions];

  int iOption = 0;

  // add characters Moveset to Action Options
  for (int iMove = 0; iMove < character[0].numberOfMoves; iMove++) {
    if (character[0].Moveset[iMove][0].remainingUses > 0) {
      actionOptions[iOption] = character[0].Moveset[iMove];
      iOption++;
    }
  }

  // add item actions to Action Options
  for (int iItem = 0; iItem < numberOfItems; iItem++) {
    actionOptions[iOption] = inventory[iItem].action;
    iOption++;
  }
  numberOfOptions = iOption;
};