#include "Heal_Move.h"

#include <iostream>

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
  remainingUses = maxUses;  // remaining uses always starts at the maximum
  healAmount = restoreAmount;
  maxCoolDown = coolDown;
  remainingCoolDown = 0;  // a heal_move's cooldown always starts at 0 (can be
                          // used immedietly on the first turn of battle)
}

void Heal_Move::Execute(Character* Actor, Character* Target) {
  std::cout << Actor[0].Name << " used " << name
            << std::endl;  // remember to check if the remaining cool down is <
                           // 0 before executing a heal move

  if (Target[0].HP + healAmount + Actor[0].baseHeal < Target[0].maxHP) {
    Target[0].HP =
        Target[0].HP + healAmount +
        Actor[0].baseHeal;  // heal amount formula (baseHeal is used with
                            // addition rather than multiplication to lessen the
                            // impact of healing in the lategame)
  } else {
    // prevents healing above a character's maximum health
    Target[0].HP = Target[0].maxHP;
  }
  std::cout << Target[0].Name << " recovered " << healAmount + Actor[0].baseHeal
            << " health" << std::endl;

  remainingCoolDown = maxCoolDown;
  remainingUses--;
}