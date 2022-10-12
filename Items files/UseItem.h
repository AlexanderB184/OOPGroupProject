#ifndef USEITEM_H
#define USEITEM_H

#include "Item.h"
#include "Action.h"
#include <string>

using namespace std;

// Class definition for UseItem class
class UseItem: public Item {
    public:
        UseItem();
        UseItem(string name, string type, int quantity);
        ~UseItem();
};
#endif //USEITEM_H