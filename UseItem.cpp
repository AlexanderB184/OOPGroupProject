#include "UseItem.h"

#include <iostream>
#include <string>

#include "Action.h"
#include "Character.h"
#include "Item.h"
#include "Status.h"

using namespace std;

// implementation of the UseCureItem function
void UseCureItem::Execute(Character* Target, Character* Actor) {
  // Checks if status effect is active
  bool check = true;
  // Loops through all current status effects
  for (int i = 0; i < Target[0].numberOfEffects; i++) {
    if (Target[0].StatusEffect[i][0].statusType == statusToRemove) {
      // Removes effect from character
      Target[0].removeStatus(i);
      // Informs user what happened
      cout << "The " << statusToRemove << " status effect was removed from "
           << Target[0].Name << "." << endl;
      check = false;
    }
  }
  // Runs if status effect removed is not present on character.
  if (check == true) {
    // Tells user if characters does not possess status.
    cout << "This has no effect." << endl;
  }
}

// implementation of the UseHealItem function
void UseHealItem::Execute(Character* Target, Character* Actor) {
  // Adds healAmount to character's hp
  Target[0].HP = Target[0].HP + healAmount;
  // Checks if hp has gone over max
  if (Target[0].HP > Target[0].maxHP) {
    // If hp over max, reduces it back to max
    Target[0].HP = Target[0].maxHP;
  }
}

// implementation of the UseHealItem function
void UseStatusItem::Execute(Character* Target, Character* Actor) {
  // Decides effect applied based on item name
  // For regeneration effect item
  if (name == "Regen Elixir") {
    // Creates regen status effect
    statusEffect = new RegenEffect(10, 4);
    // Informs user an invalid item name is present
  } else {
    cout << "Invalid item name." << endl;
  }

  // Applies status effect to character
  Target[0].addStatus(statusEffect);

  // Informs user what happened on item use.
  cout << "The " << statusEffect << " was applied to " << Target << "." << endl;
}

UseCureItem::UseCureItem(string _statusToRemove, int _quantity) {
  statusToRemove = _statusToRemove;
  quantity = _quantity;
}

UseHealItem::UseHealItem(int _healAmount, int _quantity) {
  healAmount = _healAmount;
  quantity = _quantity;
};

UseStatusItem::UseStatusItem(Status* status, int _quantity) {
  statusEffect = status;
  quantity = _quantity;
}
UseCureItem* UseCureItem::clone() {
  UseCureItem* newCure = new UseCureItem(statusToRemove, quantity);
  return newCure;
}

UseStatusItem* UseStatusItem::clone() {
  Status* newStatus = statusEffect[0].clone();
  UseStatusItem* newStatusAction = new UseStatusItem(newStatus, quantity);
  return newStatusAction;
}

UseHealItem* UseHealItem::clone() {
  UseHealItem* newHeal = new UseHealItem(healAmount, quantity);
  return newHeal;
}
