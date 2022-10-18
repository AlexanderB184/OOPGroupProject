#include "UseStatusItem.h"

#include <iostream>

#include "Status.h"

using namespace std;

UseStatusItem::UseStatusItem(Status* status) { StatusEffect = status; }

// implementation of the UseHealItem function
void UseStatusItem::Execute(Character* Target, Character* Actor) {
  // Needs to be combined
  Target[0].addStatus(StatusEffect[0].clone());

  // Informs user what happened
  cout << "The " << StatusEffect << " was applied to " << Target << "." << endl;
}