#include "HumanController.h"

#include <string>
#include <iostream>

using namespace std;

Action* HumanController::getAction() { 
    bool isValidOption = false;
    string userInput;
    while (!isValidOption) {
      cout << "Select an Option" << endl;
      for (int iOption = 0; iOption < numberOfOptions; iOption++){
        cout << actionOptions[iOption][0].name << ': ' << actionOptions[iOption][0].description << endl;
      }
      cin >> userInput;
      cout << endl;
      for (int iOption = 0; iOption < numberOfOptions; iOption++) {
        if (userInput == actionOptions[iOption][0].name) {
          return actionOptions[iOption];
        }
      }
      cout << "Invalid Option, try again" << endl;
    }
};