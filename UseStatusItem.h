#ifndef USESTATUSITEM_H
#define USESTATUSITEM_H

#include <string>

#include "Character.h"
#include "Status.h"
#include "UseItem.h"

using namespace std;

// Class definition for UseStatusItem class
class UseStatusItem : public UseItem {
 private:
  Status* StatusEffect;

 public:
  UseStatusItem(Status* status);
  void Execute(Character* Target, Character* Actor);
};

#endif  // USESTATUSITEM_H