#ifndef ATTACK_MOVE_H
#define ATTACK_MOVE_H

#include "Character.h"
#include "Move.h"

class Attack_Move : public Move {
 public:
  Attack_Move();  // default constructor
  Attack_Move(std::string attackName, int maxUses, int pow,
              int acc);  // constructor
  void Execute(
      Character* Actor,
      Character* Target);  // attacks the target using stats from both
                           // actor and target to determine damage and hitrate

  Attack_Move* clone();    // Makes a clone object

  int damage;    // amount of damage the move does when attack and defence are
                 // equal
                 
  int accuracy;  // number from 1-100 representing the chance of success as a
                 // percentage
};
#endif