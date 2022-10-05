#ifndef SPECIAL_ATTACK_MOVE_H
#define SPECIAL_ATTACK_MOVE_H

#include "Move.h"

class statusEffect;

class Special_Attack_Move : public Move {
 public:
  Special_Attack_Move();
  Special_Attack_Move();
  void Execute(Character Actor, Character Target);

  // statusEffect status;
  int damage;
  int attack_accuracy;
  int status_accuracy;
};
#endif