#include <iostream>
#include <string>
#include "UseItem.h"
#include "Item.h"
#include "Action.h"
#include "Character.h"
#include "Battle.h"
#include "Status.h"

using namespace std;

// implementation of the UseItem function
UseItem::UseItem() {
  name = "Unnamed";
  type = "No Type";
  quantity = 0;
}

UseItem::UseItem(string name, string type, int quantity, Character* Target, Character* Actor){
  // Determines what function is used based on type
  // Runs function for cure items
  if (type == "Cure"){
    UseCureItem::Execute(name, Target, Actor);
  // Runs function for heal items
  } else if (type == "Heal"){
    UseHealItem::Execute(name, Target, Actor);
  // Runs function for status items
  } else if (type == "Status"){
    UseStatusItem::Execute(name, Target, Actor);
  } else {
    cout << "Invalid item type error occured!" << endl;
  }
}

// Implementation of the default UseItem deconstructor
UseItem::~UseItem(){};

// implementation of the UseCureItem function
void UseCureItem::Execute(string name, Character* Target, Character* Actor){

  // Determines what item is used of cure type based on name.
  // Cure for stun effect, sets status to removes as stun.
  if (name == "Stun Cure") {
    statusToRemove = StunEffect*;
  // Cure for burn effect, sets status to remove as burn.
  } else if (name == "Burn Cure") {
    statusToRemove = BurnEffect*;
  // Case if invalid option occurs
  } else {
    cout << "Invalid item name" << endl;
  }

  // Checks if status effect is active
  bool check = true;
  // Loops through all current status effects
  for (int i = 0; i < Target[0].numberOfEffects; i++) {
    if (Target[0].StatusEffect[i] == statusToRemove) {
      // Removes effect from character
      Target[0].removeStatus(i);
      // Informs user what happened
      cout << "The " << statusToRemove << " status effect was removed from "
           << Target << "." << endl;
      check = false;
    }
  }
  if (check == true){
    // Tells user if characters does not possess status.
    cout << "The " << name << " has no effect." << endl;
  }
}

// implementation of the UseHealItem function
void UseHealItem::Execute(string name, Character* Target, Character* Actor) {

  // Decides amount healed based on item name
  // For full heal item
  if (name == "Full Heal"){
    healAmount = Target[0].maxHP;
    cooldown = currentTurn + 3;
  // For set amount heal item
  } else if (name == "Basic Heal") {
    healAmount = 40;
    cooldown = currentTurn + 2;
  // Informs user and invalid item name is present
  } else {
    cout << "Invalid item name." << endl;
  }

  // Checks if cooldown is active
  if (cooldown <= currentTurn) {
    // Adds healAmount to character's hp
    Target[0].HP = Target[0].HP + healAmount;
    // Checks if hp has gone over max
    if (Target[0].HP > Target[0].maxHP) {
      // If hp over max, reduces it back to max
      Target[0].HP = Target[0].maxHP;
    }
  } else {
    // Tells user if cooldown not over and how long left.
    cout << "Item on cooldown, " << cooldown - currentTurn << " turns left."
         << endl;
  }
}

// implementation of the UseHealItem function
void UseStatusItem::Execute(string name, Character* Target, Character* Actor){
  // Needs to be combined 
  Target[0].addStatus(StatusEffect);

  // Informs user what happened
  cout << "The " << StatusEffect << " was applied to " << Target << "." << endl;
}