#include <iostream>
#include "Item.h"

using namespace std;

// Implementation of the Default Item Constructor
Item::Item(){
  name = "Unnamed";
  type = "No Type";
  quantity = 0;
};

// Implementation of an Item constructor taking a name, type, and quantity.
Item::Item(string iName, string iType, int iQuantity){
  name = iName;
  type = iType;
  quantity = iQuantity;
};

// Implementation of the default item deconstructor
Item::~Item(){};