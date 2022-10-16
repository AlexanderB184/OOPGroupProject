#include "Status_Move.h"

#include <math.h>

#include <iostream>

Status_Move::Status_Move() {
  name = "a";
  initialUses = 1;
  remainingUses = 1;
  status = nullptr;
  statusName = "Burn";
  statusAccuracy = 100;
}

Status_Move::Status_Move(std::string statusMoveName, int maxUses,
                         Status* _status, std::string _statusName, int acc) {
  name = statusMoveName;
  initialUses = maxUses;
  remainingUses = maxUses;  // remaining uses always starts at the maximum
  status = _status;
  statusName = _statusName;
  statusAccuracy = acc;
}

Status_Move* Status_Move::clone() {
  Status_Move* clonedStatus =
      new Status_Move(name, initialUses, status, statusName, statusAccuracy);
  return clonedStatus;
}

void Status_Move::Execute(Character* Actor, Character* Target) {
  std::cout << Actor[0].Name << " used " << name << std::endl;

  int random = (0 + (rand() % 100));
  if (random >= statusAccuracy * pow(0.95, Target[0].baseSpeed / 10)) {
    Target[0].addStatus(status[0].clone());
    std::cout << Target[0].Name << " became inflicted with " << statusName
              << std::endl;
  } else {
    std::cout << "The attack missed!" << std::endl;
  }

  remainingUses--;
}