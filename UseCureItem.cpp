#include "UseCureItem.h"

#include <iostream>

#include "Character.h"

using namespace std;

// implementation of the UseCureItem function
UseCureItem::Execute(Character* Target, Character* Actor) {
  // Checks if status effect is active
  int check = 0;
  // Loops through all current status effects
  for (int i = 0; i < Target[0].numberOfEffects; i++) {
    if (Target[0].StatusEffect[i] == StatusToRemove) {
      // Removes effect from character
      Target[0].removeStatus(StatusToRemove);
      // Informs user what happened
      cout << "The " << StatusToRemove << " status effect was removed from "
           << Target << "." << endl;
      j++;
    }
  }
  if (check == 0) {
    // Tells user if characters does not possess status.
    cout << "Character doesn't have " << StatusToRemove << endl;
  }
}