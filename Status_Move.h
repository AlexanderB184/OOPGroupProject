#ifndef STATUS_MOVE_H
#define STATUS_MOVE_H

#include "Move.h"
#include "Status.h"

class Status_Move : public Move {
 public:
  Status_Move();
  Status_Move(std::string statusMoveName, int maxUses, Status* _status,
              std::string _statusName, int acc);
  void Execute(Character* Actor, Character* Target);
  Status_Move* clone();

  std::string statusName;  // name of the status condition inflicted
  Status* status;          // pointer to the status condition
  int statusAccuracy;  // number from 1-100 representing the chance of success
                       // as a percentage
};
#endif