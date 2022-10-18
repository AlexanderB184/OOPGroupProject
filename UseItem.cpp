#include <iostream>
#include <string>
#include "UseItem.h"
#include "Item.h"
#include "Action.h"
#include "Character.h"
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
    // Runs cure item function
    UseCureItem::Execute(name, Target, Actor);
  // Runs function for heal items
  } else if (type == "Heal"){
    // Runs heal item function
    UseHealItem::Execute(name, Target, Actor);
  // Runs function for status items
  } else if (type == "Status"){
    // Runs status item function
    UseStatusItem::Execute(name, Target, Actor);
  // Runs if all types fail
  } else {
    // Informs user that an error has occured in the type variable.
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
    statusToRemove = "Stun";
  // Cure for burn effect, sets status to remove as burn.
  } else if (name == "Burn Cure") {
    statusToRemove = "Burn";
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
  // Runs if status effect removed is not present on character.
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
  // For set amount heal item
  } else if (name == "Basic Heal") {
    healAmount = 40;
  // Informs user an invalid item name is present
  } else {
    cout << "Invalid item name." << endl;
  }

  // Adds healAmount to character's hp
  Target[0].HP = Target[0].HP + healAmount;
  // Checks if hp has gone over max
  if (Target[0].HP > Target[0].maxHP) {
    // If hp over max, reduces it back to max
    Target[0].HP = Target[0].maxHP;
  }
}

// implementation of the UseHealItem function
void UseStatusItem::Execute(string name, Character* Target, Character* Actor){

  // Decides effect applied based on item name
  // For regeneration effect item
  if (name == "Regen Elixir"){
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