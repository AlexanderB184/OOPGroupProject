#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "Character.h"
#include "Item.h"
#include "Move.h"
#include "Status.h"
#include "UseItem.h"

using namespace std;

class Action;
class Item;
// DELETE WHEN PROPER ACTION AND ITEM CLASSES ARE ADDED

class Controller {
 public:
  Character* character;
  Item* inventory;
  int numberOfItems;
  Action** actionOptions;
  int numberOfOptions;

  // virtual get action function has different implementations for the computer
  // and human controllers
  virtual Action* getAction() = 0;

  // Generate options creates a list of possible actions a user can take
  void generateOptions();

  // Add and remove an item from a players inventory
  void addItem(Item*);

  void removeItem(int index);
};

#endif