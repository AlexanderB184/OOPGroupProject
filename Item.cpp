#include "Item.h"

#include <iostream>

using namespace std;

// Implementation of the Default Item Constructor
Item::Item() {
  // Declares standard variables
  name = "Unnamed";
  type = "No Type";
  quantity = 0;
};

// Implementation of an Item constructor taking a name, type, and quantity.
Item::Item(string iName, string iType, int iQuantity, UseItem* _action) {
  // Declares variables from input
  name = iName;
  type = iType;
  quantity = iQuantity;
  action = _action;
};

// Implementation of the default item deconstructor
Item::~Item(){};