#include "UseHealItem.h"

#include <iostream>

#include "Character.h"

using namespace std;

// implementation of the UseHealItem function
UseHealItem::Execute() {
  // Checks if cooldown is active
  if (cooldown <= currentTurn) {
    // Adds healAmount to character's hp
    Target[0].HP = Target[0].HP + healAmount;
    // Checks if hp has gone over max
    if (Target[0].HP > Target[0].maxHP) {
      // If hp over max, reduces it back to max
      Target[0].HP = Target[0].maxHP;
    }
    // Sets cooldown based on item used
    switch (name) {
      // Sets cooldown for full heal item
      case:
        "Full Heal" int cooldown = currentTurn + 4;
      // Sets cooldown for basic heal item
      case:
        "Basic Heal" int cooldown = currentTurn + 2;
      // Informs user and invalid item name is present
      default:
        cout << "Invalid item name." << endl;
    }
  } else {
    // Tells user if cooldown not over and how long left.
    cout << "Item on cooldown, " << cooldown - currentTurn << " turns left."
         << endl;
  }
}