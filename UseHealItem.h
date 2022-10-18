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
  int healAmount;

 public:
  UseHealItem(int _healAmount);
  void Execute(Character* Target, Character* Actor);
};

#endif  // USEHEALITEM_H