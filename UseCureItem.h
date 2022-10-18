#ifndef USECUREITEM_H
#define USECUREITEM_H

#include <string>

#include "UseItem.h"

using namespace std;

// Class definition for UseCureItem class
class UseCureItem : public UseItem {
 private:
  // Determines what item is used of cure type based on name
  string statusToRemove;

 public:
  UseCureItem(string statusToRemove);
  void Execute(Character* Target, Character* Actor);
};

#endif  // USECUREITEM_H