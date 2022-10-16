#ifndef SPECIAL_ATTACK_MOVE_H
#define SPECIAL_ATTACK_MOVE_H

#include "Move.h"

class Special_Attack_Move : public Move {
 public:
  Special_Attack_Move();
  Special_Attack_Move(std::string attackName, int maxUses, int pow, int acc,
                      Status* _status, std::string _statusName, int statusAcc);
  void Execute(Character* Actor, Character* Target);

  int damage;    // amount of damage the move does when attack and defence are
                 // equal
  int accuracy;  // number from 1-100 representing the chance of success as a
                 // percentage
  std::string statusName;  // name of the status condition inflicted
  Status* status;          // pointer to the status condition
  int statusAccuracy;      // a seperate check for if a status condition occurs
                           // (another number from 1-100)
};
#endif