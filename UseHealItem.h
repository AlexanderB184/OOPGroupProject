#ifndef USEHEALITEM_H
#define USEHEALITEM_H

#include <string>

#include "Battle.h"
#include "Character.h"
#include "UseItem.h"

using namespace std;

// Class definition for UseHealItem class
class UseHealItem : public UseItem {
 private:
  switch (name) {
    case:
      "Full Heal" int healAmount = maxHP;
      int cooldown = 0;
    case:
      "Basic Heal" int healAmount = 15;
      int cooldown = 0;
    // Informs user and invalid item name is present
    default:
      cout << "Invalid item name." << endl;
  }

 public:
  Execute(Character* Target, Character* Actor);
};

#endif  // USEHEALITEM_H