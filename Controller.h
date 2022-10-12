#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Character.h"
#include "Status.h"

#include <string>

using namespace std;

class Action;
class Item;
//DELETE WHEN PROPER ACTION AND ITEM CLASSES ARE ADDED

class Controller {
    public:
     Character* character;
     Item* inventory;
     int numberOfItems;
     Action** actionOptions;
     int numberOfOptions;
     Controller();
     Controller(Character*, Item*, int);
     ~Controller();
     virtual Action* getAction() = 0;
     void generateOptions();

     void addItem(Item*);
     void removeItem(int index);
};

#endif