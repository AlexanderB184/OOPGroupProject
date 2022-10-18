#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>

#include "Attack_Move.h"
#include "Battle.h"
#include "Character.h"
#include "ComputerController.h"
#include "Controller.h"
#include "Heal_Move.h"
#include "HumanController.h"

class UI {
 public:
  UI();
  ~UI();
  void selectCharacter(Controller*);
  Item* selectItem();
};

#endif