#include "UseHealItem.h"

#include <iostream>

#include "Character.h"

using namespace std;

UseHealItem::UseHealItem(int _healAmount) { healAmount = _healAmount; };

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