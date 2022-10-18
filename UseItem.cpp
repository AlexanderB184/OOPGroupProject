#include "UseItem.h"

#include <iostream>
#include <string>

#include "Action.h"
#include "Character.h"
#include "Item.h"
#include "Status.h"

using namespace std;

UseStatusItem::~UseStatusItem() { delete statusEffect; }

// Implementation of the UseCureItem function
void UseCureItem::Execute(Character* Target, Character* Actor) {
  cout << Actor[0].Name << " used " << name << "." << endl;
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
  // Decreases quantity by 1
  quantity--;
}

// implementation of the UseHealItem function
void UseHealItem::Execute(Character* Target, Character* Actor) {
  cout << Actor[0].Name << " used " << name << endl;
  // Adds healAmount to character's hp
  Target[0].HP = Target[0].HP + healAmount;
  cout << Target[0].Name << " healed " << healAmount << " health" << endl;
  // Checks if hp has gone over max
  if (Target[0].HP > Target[0].maxHP) {
    // If hp over max, reduces it back to max
    Target[0].HP = Target[0].maxHP;
  }
  // Decreases quantity by 1
  quantity--;
}

// implementation of the UseHealItem function
void UseStatusItem::Execute(Character* Target, Character* Actor) {
  cout << Actor[0].Name << " used " << name << "." << endl;
  // Applies status effect to character
  Target[0].addStatus(statusEffect[0].clone());

  // Informs user what happened on item use.
  cout << "The " << statusEffect[0].statusType << " was applied to "
       << Target[0].Name << "." << endl;
  // Decreases quantity by 1
  quantity--;
}

// Implementation of UseCureItem function
UseCureItem::UseCureItem(string _name, string _statusToRemove, int _quantity) {
  // Declares variables from inputs
  name = _name;
  statusToRemove = _statusToRemove;
  quantity = _quantity;
}

// Implementation of UseHealItem function
UseHealItem::UseHealItem(string _name, int _healAmount, int _quantity) {
  // Declares variables from inputs
  name = _name;
  healAmount = _healAmount;
  quantity = _quantity;
};

// Implementation of UseStatusItem function
UseStatusItem::UseStatusItem(string _name, Status* status, int _quantity) {
  // Declares variables from inputs
  name = _name;
  statusEffect = status;
  quantity = _quantity;
}

// Implementation of UseCureItem clone function
UseCureItem* UseCureItem::clone() {
  // Declares new varibale from free memory
  UseCureItem* newCure = new UseCureItem(name, statusToRemove, quantity);
  // Returns variable to request location
  return newCure;
}

// Implementation of UseStatusItem clone function
UseStatusItem* UseStatusItem::clone() {
  // Declares new status variable from statusEffect 
  Status* newStatus = statusEffect[0].clone();
  // Declares new varibale from free memory
  UseStatusItem* newStatusAction = new UseStatusItem(name, newStatus, quantity);
  // Returns variable to request location
  return newStatusAction;
}

// Implementation of UseHealItem clone function
UseHealItem* UseHealItem::clone() {
  // Declares new varibale from free memory
  UseHealItem* newHeal = new UseHealItem(name, healAmount, quantity);
  // Returns variable to request location
  return newHeal;
}
