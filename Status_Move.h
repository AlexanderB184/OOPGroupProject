#ifndef STATUS_MOVE_H
#define STATUS_MOVE_H

#include "Move.h"
#include "Status.h"

class Status_Move : public Move {
 public:
  Status_Move();
  Status_Move(std::string statusMoveName, int maxUses, Status* _status, std::string _statusName, int acc);
  void Execute(Character* Actor, Character* Target);

  std::string statusName;
  Status* status;
  int accuracy;
};
#endif