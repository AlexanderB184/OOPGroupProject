#ifndef USECUREITEM_H
#define USECUREITEM_H

#include <string>

#include "UseItem.h"

using namespace std;

// Class definition for UseCureItem class
class UseCureItem : public UseItem {
 private:
  // Determines what item is used of cure type based on name
  switch (name) {
    // Cure for stun effect, sets status to removes as stun.
    case:
      "Stun Cure" string StatusToRemove = "Stun";
    // Cure for burn effect, sets status to remove as burn.
    case:
      "Burn Cure" string StatusToRemove = "Burn";
    default:
      // Case if invalid option occurs
      cout << "Invalid item name" << endl;
  }

 public:
  Execute(Character* Target, Character* Actor);
};

#endif  // USECUREITEM_H