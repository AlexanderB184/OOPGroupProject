#ifndef UI_H
#define UI_H

#include "Battle.h"
#include "Controller.h"
#include "ComputerController.h"
#include "HumanController.h"
#include "Character.h"
#include "Attack_Move.h"
#include "Heal_Move.h"

#include <string>
#include <iostream>

class UI {
    public:
     UI();
     ~UI();
     void selectCharacter(Controller *);
     Item* selectItem();
};

#endif