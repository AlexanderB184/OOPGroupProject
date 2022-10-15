#include "Status_Move.h"
#include <iostream>

Status_Move::Status_Move() {
    name = "a";
  initialUses = 1;
  remainingUses = 1;
  status = nullptr;
  statusName = "Burn";
  accuracy = 100;
}

Status_Move::Status_Move(std::string statusMoveName, int maxUses, Status* _status, std::string _statusName, int acc) {
    name = statusMoveName;
    initialUses = maxUses;
    remainingUses = maxUses;
    status = _status;
    statusName = _statusName;
    accuracy = acc;
}

void Status_Move::Execute(Character* Actor, Character* Target) { //currently non-functional
    //switch (statusName) {
        //case "Burn":
       // Status** newStatus = new BurnEffect * [1];
        //newStatus[0] = new BurnEffect(status[0].damageRate,status[0].duration);
       // case "Regen":
          //  }
    Target[0].addStatus( status[0].clone() );
    //Target[0].addStatus(newStatus);
}