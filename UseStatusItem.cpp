#include <iostream>
#include "UseStatusItem.h"
#include "Status.h"

using namespace std;

// implementation of the UseHealItem function
UseStatusItem::Execute(Character* Target, Character* Actor){
  // Needs to be combined 
  Target[0].addStatus(StatusEffect);

  // Informs user what happened
  cout << "The " << StatusEffect << " was applied to " << Target << "." << endl;
  
}