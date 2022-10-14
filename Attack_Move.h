#ifndef ATTACK_MOVE_H
#define ATTACK_MOVE_H

#include "Move.h"
#include "Character.h"

class Attack_Move : public Move {
 public:
  Attack_Move();
  Attack_Move(std::string attackName, int maxUses, int pow, int acc);
  void Execute(Character* Actor, Character* Target);
  Attack_Move* clone();
  int damage;
  int accuracy;  // number from 1-100 representing the chance of success as a
                 // percentage
};
#endif