#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

// Class definition for item class
class Item {
    private:
        string name;
        string type;
        int quantity;
    public:
        Item();
        Item(string iName, string iType, int iQuantity);
        ~Item();
};
#endif //ITEM_H