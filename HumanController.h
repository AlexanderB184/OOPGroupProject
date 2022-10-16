#ifndef HUMAN_CONTROLLER_H
#define HUMAN_CONTROLLER_H

#include <string>

#include "Controller.h"

using namespace std;

class HumanController : public Controller {
 public:
  Action* getAction();
  HumanController();
  HumanController(Character*, Item*, int);
  ~HumanController();
};

#endif