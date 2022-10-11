#include "ComputerController.h"

#include <string>

using namespace std;

Action* ComputerController::getAction(){
  //return a random action from the list of possible options
  return actionOptions[rand() % numberOfOptions];
};