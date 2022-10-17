#ifndef STATUS_MOVE_H
#define STATUS_MOVE_H

#include "Move.h"
#include "Status.h"

class Status_Move : public Move {
 public:
  Status_Move();  // default constructor
  Status_Move(std::string statusMoveName, int maxUses, Status* _status,
              std::string _statusName, int acc);  // constructor
  void Execute(Character* Actor,
               Character* Target);  // inflicts the Target with a status
                                    // condition with the accuracy determined by
                                    // the base speed of the Target
  Status_Move* clone();             // Makes a clone object

  std::string statusName;  // name of the status condition inflicted
  Status* status;          // pointer to the status condition
  int statusAccuracy;  // number from 1-100 representing the chance of success
                       // as a percentage
};
#endif