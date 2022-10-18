#ifndef HUMAN_CONTROLLER_H
#define HUMAN_CONTROLLER_H

#include <string>

#include "Controller.h"

using namespace std;

class HumanController : public Controller {
 public:
  Action* getAction();  // Get action asks the user for which action the user
                        // wants to perform
  HumanController();
  HumanController(Character*, Item*,
                  int);  // Constructor takes in the character and their items
  ~HumanController();
};

#endif