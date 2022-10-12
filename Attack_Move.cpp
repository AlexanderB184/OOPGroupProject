#include "Attack_Move.h"

#include <iostream>

Attack_Move::Attack_Move() {
  name = "a";
  initialUses = 1;
  remainingUses = 1;
  damage = 1;
  accuracy = 100;
}

Attack_Move::Attack_Move(std::string attackName, int maxUses, int pow,
                         int acc) {
  name = attackName;
  initialUses = maxUses;
  remainingUses = maxUses;
  damage = pow;
  accuracy = acc;
}

void Attack_Move::Execute(Character* Actor, Character* Target) {
  std::cout << Actor[0].Name << " used " << name << std::endl;

  int random = (0 + (rand() % 101)) * Actor[0].baseSpeed / Target[0].baseSpeed;
  if (random >= accuracy) {
    if (Target[0].HP - (damage * Actor[0].baseAtt / Target[0].baseDef) > 0) {
      Target[0].HP = Target[0].HP - (damage * Actor[0].baseAtt / Target[0].baseDef);
    } else {
      Target[0].HP = 0;
    }
    std::cout << Target[0].Name << " lost "
              << damage * Actor[0].baseAtt / Target[0].baseDef << " health"
              << std::endl;
  } else {
    std::cout << "The attack missed!" << std::endl;
  }

  remainingUses--;
}