#ifndef STATUS_MOVE_H
#define STATUS_MOVE_H

#include "Move.h"

class statusEffect;

class Status_Move : public Move {
 public:
  Status_Move();
  Status_Move();
  void Execute(Character Actor, Character Target);

  // statusEffect status;
  int accuracy;
};
#endif