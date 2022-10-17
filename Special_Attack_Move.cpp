#include "Special_Attack_Move.h"

#include <math.h>

#include <iostream>

Special_Attack_Move::Special_Attack_Move() {
  name = "a";
  initialUses = 1;
  remainingUses = 1;
  damage = 1;
  accuracy = 100;
  status = nullptr;
  statusName = "Burn";
  statusAccuracy = 100;
}

Special_Attack_Move::Special_Attack_Move(std::string attackName, int maxUses,
                                         int pow, int acc, Status* _status,
                                         std::string _statusName,
                                         int statusAcc) {
  name = attackName;
  initialUses = maxUses;
  remainingUses = maxUses;  // remaining uses always starts at the maximum
  damage = pow;
  accuracy = acc;
  status = _status;
  statusName = _statusName;
  statusAccuracy = statusAcc;
}

Special_Attack_Move* Special_Attack_Move::clone() {
  Special_Attack_Move* clonedSpecial = new Special_Attack_Move(
      name, initialUses, damage, accuracy, status, statusName, statusAccuracy);
  return clonedSpecial;
}

void Special_Attack_Move::Execute(Character* Actor, Character* Target) {
  std::cout << Actor[0].Name << " used " << name << std::endl;

  int random = (0 + (rand() % 100));
  if (random <= accuracy * pow(0.95, Target[0].baseSpeed / 10)) {
    std::cout << Target[0].Name << " lost "
              << damage * Actor[0].baseAtt / Target[0].baseDef << " health"
              << std::endl;
    if (Target[0].HP - (damage * Actor[0].baseAtt / Target[0].baseDef) > 0) {
      Target[0].HP =
          Target[0].HP - (damage * Actor[0].baseAtt / Target[0].baseDef);
      std::cout << Target[0].Name << " has " << Target[0].HP
                << " health remaining" << std::endl;

      // status check (only happens if the Target does not die from the attack)
      random = (0 + (rand() % 100));
      if (random <= statusAccuracy) {  // the additional status check is not
                                       // based on speed
        Target[0].addStatus(status[0].clone());
        std::cout << Target[0].Name << " became inflicted with " << statusName
                  << std::endl;
      }  // the additional status check only outputs a message if it succeeds

    } else {
      Target[0].HP = 0;
      Target[0].dead = true;
      std::cout << Target[0].Name << " has died" << std::endl;
    }

  } else {
    std::cout << "The attack missed!" << std::endl;
  }

  remainingUses--;
}