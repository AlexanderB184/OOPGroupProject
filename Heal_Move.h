#ifndef HEAL_MOVE_H
#define HEAL_MOVE_H

#include "Move.h"

class Heal_Move : public Move {
 public:
  Heal_Move();  // default constructor
  Heal_Move(std::string healName, int maxUses, int restoreAmount,
            int coolDown);  // constructor
  void Execute(
      Character* Actor,
      Character* Target);  // heals the Actor based on the Actor's stats
  Heal_Move* clone();      // Makes a clone object

  int healAmount; // healing power of the move (higher number = move powerful)
  int maxCoolDown; // remove this
  int remainingCoolDown; // remove this
};
#endif // remove all mentions of CoolDown