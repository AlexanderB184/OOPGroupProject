#ifndef USEITEM_H
#define USEITEM_H

#include "Item.h"
#include "Action.h"
#include <string>

using namespace std;

// Class definition for UseItem class
class UseItem : public Action{
    public:
     string type;
     Item* item;
     int quantity;
     UseItem();
     UseItem(string name, string type, int quantity);
     ~UseItem();
};
#endif //USEITEM_H