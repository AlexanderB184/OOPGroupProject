#ifndef COMPUTER_CONTROLLER_H
#define COMPUTER_CONTROLLER_H

#include "Controller.h"

#include <string>

using namespace std;

class ComputerController: public Controller {
    public:
     Action* getAction();
     using Controller::Controller;
};

#endif