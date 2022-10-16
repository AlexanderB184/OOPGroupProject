#ifndef ITEM_H
#define ITEM_H

#include <string>
//#include "UseItem.h"
class UseItem;

using namespace std;

// Class definition for item class
class Item {
    private:
        string name;
        string type;
        int quantity;
        
    public:
     UseItem* action;
     Item();
     Item(string iName, string iType, int iQuantity, UseItem* action);
     ~Item();
};
#endif //ITEM_H