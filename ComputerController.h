#ifndef COMPUTER_CONTROLLER_H
#define COMPUTER_CONTROLLER_H

#include "Controller.h"

#include <string>

using namespace std;

class ComputerController: public Controller {
    public:
     Action* getAction(); //Get action uses random chance to decide which move to make
     ComputerController();
     ComputerController(Character*, Item*, int); //Constructor takes in the character and their items
     ~ComputerController();
};

#endif