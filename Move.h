#include "Character.h"

#ifndef MOVE_H
#define MOVE_H

#include "Action.h"

class Move : public Action {
 public:
  void Reset_Uses();  // set remainingUses to initialUses
  virtual Move* clone() = 0; // Makes a clone object
  
  int remainingUses;
  int initialUses;
};
#endif