#include <string>

using namespace std;

#include "Character.h"
#include "Status.h"

BurnEffect::BurnEffect() {
  duration = 0;
  damageRate = 0;
  statusType = "Burn";
}

BurnEffect::BurnEffect(int _damageRate, int _duration) {
  duration = _duration;
  damageRate = _damageRate;
  statusType = "Burn";
}

void BurnEffect::Apply(Character* Target) {
  Target[0].HP -= damageRate;  // Deal damage to target
  duration -= 1;               // decrement remaining duration
}

BurnEffect* BurnEffect::clone() {
  BurnEffect* clonedBurn = new BurnEffect(damageRate, duration);
  return clonedBurn;
}

RegenEffect::RegenEffect() {
  duration = 0;
  healRate = 0;
  statusType = "Regen";
}

RegenEffect::RegenEffect(int _healRate, int _duration) {
  duration = _duration;
  healRate = _healRate;
  statusType = "Regen";
}

void RegenEffect::Apply(Character* Target) {
  Target[0].HP += healRate;  // Heal target
  duration -= 1;             // decrement remaining duration
}

RegenEffect* RegenEffect::clone() {
  RegenEffect* clonedRegen = new RegenEffect(healRate, duration);
  return clonedRegen;
}

StunEffect::StunEffect() {
  duration = 0;
  chanceToMissTurn = 0;
  statusType = "Stun";
}

StunEffect::StunEffect(int _chanceToMissTurn, int _duration) {
  duration = _duration;
  chanceToMissTurn = _chanceToMissTurn;
  statusType = "Stun";
}

void StunEffect::Apply(Character* Target) {
  if (rand() % 100 <
      chanceToMissTurn) {  // random chance to make character miss next turn
    Target[0].missNextTurn = true;
  }
  duration -= 1;  // decrement duration
}

StunEffect* StunEffect::clone() {
  StunEffect* clonedStun = new StunEffect(chanceToMissTurn, duration);
  return clonedStun;
}