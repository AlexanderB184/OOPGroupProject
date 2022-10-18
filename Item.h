#ifndef ITEM_H
#define ITEM_H

#include <string>
class UseItem;

using namespace std;

// Class definition for item class
class Item {
    private:
     // Declares variables
     string name;
     string type;
     int quantity;
        
    public:
     // Declares functions
     UseItem* action;
     Item();
     Item(string iName, string iType, int iQuantity, UseItem* action);
     ~Item();
};
#endif //ITEM_H