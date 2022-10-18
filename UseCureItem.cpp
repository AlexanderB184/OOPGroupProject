#include "UseCureItem.h"

#include <iostream>

#include "Character.h"

using namespace std;

UseCureItem::UseCureItem(string _statusToRemove) {
  statusToRemove = _statusToRemove;
}

// implementation of the UseCureItem function
void UseCureItem::Execute(Character* Target, Character* Actor) {
  // Checks if status effect is active
  int check = 0;
  // Loops through all current status effects
  for (int i = 0; i < Target[0].numberOfEffects; i++) {
    if (Target[0].StatusEffect[i][0].statusType == statusToRemove) {
      // Removes effect from character
      Target[0].removeStatus(i);
      // Informs user what happened
      cout << "The " << statusToRemove << " status effect was removed from "
           << Target[0].Name << "." << endl;
      i--;
    }
  }
  if (check == 0) {
    // Tells user if characters does not possess status.
    cout << Target[0].Name << " doesn't have " << statusToRemove << endl;
  }
}