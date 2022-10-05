#include "Attack_Move.h"

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

// need to turn Character into a valid class

//void Attack_Move::Execute(Character Actor, Character Target) {
//
//}