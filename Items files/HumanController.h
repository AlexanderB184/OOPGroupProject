#ifndef HUMAN_CONTROLLER_H
#define HUMAN_CONTROLLER_H

#include "Controller.h"

#include <string>

using namespace std;

class HumanController: public Controller {
    public:
     Action* getAction();
     using Controller::Controller;
};

#endif