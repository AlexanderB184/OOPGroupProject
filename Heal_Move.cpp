#include "Heal_Move.h"

Heal_Move::Heal_Move() {
  name = "a";
  initialUses = 1;
  remainingUses = 1;
  healAmount = 1;
  maxCoolDown = 2;
  remainingCoolDown = 0;
}

Heal_Move::Heal_Move(std::string healName, int maxUses, int restoreAmount,
                     int coolDown) {
  name = healName;
  initialUses = maxUses;
  remainingUses = maxUses;
  healAmount = restoreAmount;
  maxCoolDown = coolDown;
  remainingCoolDown = 0;
}

// void Heal_Move::Execute(Character Actor, Character Target) {
//
// }