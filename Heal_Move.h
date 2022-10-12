#ifndef HEAL_MOVE_H
#define HEAL_MOVE_H

#include "Move.h"

class Heal_Move : public Move {
 public:
  Heal_Move();
  Heal_Move(std::string healName, int maxUses, int restoreAmount, int coolDown);
  void Execute(Character* Actor, Character* Target);

  int healAmount;
  int maxCoolDown;
  int remainingCoolDown;
};
#endif