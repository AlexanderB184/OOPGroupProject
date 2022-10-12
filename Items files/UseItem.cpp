#include <iostream>
#include "UseItem.h"

using namespace std;

// implementation of the UseItem function
UseItem::UseItem(){
  name = "Unnamed";
  type = "No Type";
  quantity = 0;

}

UseItem::UseItem(string name, string type, int quantity){
  if (quantity > 0){
    cout << "The " << name << " was used!" << endl;

    switch(type){
      case "Heal":
      //
      case "Cure":
      //
      case "Status":
      //
      default:
        // If type input doesn't work
        cout << "No valid type." << endl;
    }
    quantity--;
  } else {
    cout << "No " << name << "'s left." << endl;
  }
}

// Implementation of the default UseItem deconstructor
UseItem::~UseItem(){};