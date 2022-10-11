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

void Attack_Move::Execute(Character Actor, Character Target) {
  std::cout << Actor.Name << " used " << name << std::endl;

  int random = 0 + (rand() % 101); //I'm currently trying to think of how to incorporate speed into the accuracy formula
  if (random >= accuracy) {
    Target.HP = Target.HP - (damage * Actor.baseAtt / Target.baseDef);
    std::cout << Target.Name << " lost "
              << damage * Actor.baseAtt / Target.baseDef << " health"
              << std::endl;
  } else {
    std::cout << "The attack missed!" << std::endl;
  }

  remainingUses--;
}