#include "Attack_Move.h"

#include <math.h>

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
  remainingUses = maxUses;  // remaining uses always starts at the maximum
  damage = pow;
  accuracy = acc;
}

Attack_Move* Attack_Move::clone() {
  Attack_Move* clonedAttack =
      new Attack_Move(name, initialUses, damage, accuracy);
  return clonedAttack;
}

void Attack_Move::Execute(Character* Actor, Character* Target) {
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