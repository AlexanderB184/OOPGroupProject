#include "Heal_Move.h"

#include <iostream>

Heal_Move::Heal_Move() {
  name = "a";
  initialUses = 1;
  remainingUses = 1;
  healAmount = 1;
}

Heal_Move::Heal_Move(std::string healName, int maxUses, int restoreAmount) {
  name = healName;
  initialUses = maxUses;
  remainingUses = maxUses;  // remaining uses always starts at the maximum
  healAmount = restoreAmount;
}

Heal_Move* Heal_Move::clone() {
  Heal_Move* clonedHeal =
      new Heal_Move(name, initialUses, healAmount);
  return clonedHeal;
}

void Heal_Move::Execute(Character* Actor, Character* Target) {
  std::cout << Actor[0].Name << " used " << name
            << std::endl;  // remember to check if the remaining cool down is <
                           // 0 before executing a heal move

  if (Actor[0].HP + healAmount + Actor[0].baseHeal < Actor[0].maxHP) {
    Actor[0].HP = Actor[0].HP + healAmount +
        Actor[0].baseHeal;  // heal amount formula (baseHeal is used with
                            // addition rather than multiplication to lessen the
                            // impact of healing in the lategame)
  } else {
    // prevents healing above a character's maximum health
    Actor[0].HP = Actor[0].maxHP;
  }
  std::cout << Actor[0].Name << " recovered " << healAmount + Actor[0].baseHeal
            << " health" << std::endl;

  remainingUses--;
}