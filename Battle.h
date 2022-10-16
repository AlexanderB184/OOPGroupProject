#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>

#include "Controller.h"

using namespace std;

class Battle {
 public:
  Controller** players;
  int currentTurn;

  Battle();
  Battle(Controller**, int);
  ~Battle();

  void initBattle();
  // resets everything to its initial value

  void Turn();
  // executes a single turn

  bool runBattle();
  // executes the complete battle until a player loses
  // returns true if player 1 wins and false if player 1 loses
};

#endif