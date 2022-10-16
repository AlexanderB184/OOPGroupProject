#include "Character.h"

#ifndef MOVE_H
#define MOVE_H

#include "Action.h"

class Move : public Action {
 public:
  Move();
  void Reset_Uses();  // set remainingUses to initialUses

  int remainingUses;
  int initialUses;
};
#endif