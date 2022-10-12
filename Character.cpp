#include <string>
#include <iostream>
using namespace std;
#include "Status.h"
#include "Character.h"
#include "Move.h"

Character::Character() {
  Name = "";
  HP = 100;
  maxHP = 100;
  baseAtt = 20;
  baseDef = 20;
  baseSpeed = 20;
  baseHeal = 20;
  StatusEffect = nullptr;
  numberOfEffects = 0;
  Moveset = nullptr;
  numberOfMoves = 0;
  missNextTurn = false;
  dead = false;
};

Character::Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,int _baseSpeed, int _baseHeal, Move** _Moveset, int _numberOfMoves) {
  Name = _Name;
  HP = _maxHP;
  maxHP = _maxHP;
  baseAtt = _baseAtt;
  baseDef = _baseDef;
  baseSpeed = _baseSpeed;
  baseHeal = _baseHeal;
  StatusEffect = nullptr;
  numberOfEffects = 0;
  Moveset = _Moveset;
  numberOfMoves = _numberOfMoves;
  missNextTurn = false;
  dead = false;
};

Character::~Character(){
  if (numberOfEffects > 0) {
    for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
      delete StatusEffect[iStatus];
    }
  }
  delete StatusEffect;
  if (numberOfMoves > 0) {
    for (int iMove = 0; iMove < numberOfMoves; iMove++) {
      delete Moveset[iMove];
    }
  }
  delete Moveset;
};

void Character::ApplyStatus() { 
  if (StatusEffect == nullptr) {
    return;
  }
for (int i = 0; i < numberOfEffects;i++) {
  StatusEffect[i][0].Apply(this);
  if (StatusEffect[i][0].duration <= 0) {
    removeStatus(i);
    i--;
  }
}
if (HP > maxHP) {
    HP = maxHP;
}
else if (HP <= 0) {
    HP = 0;
    dead = true;
}
};

void Character::resetCharacter() {
  HP = maxHP;
  dead = false;
  missNextTurn = false;
  if (numberOfEffects > 0) {
    for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
      delete StatusEffect[iStatus];
    }
  }
  delete StatusEffect;
  StatusEffect = nullptr;
  numberOfEffects = 0;
  for (int iMove = 0; iMove < numberOfMoves; iMove++) {
    Moveset[iMove][0].remainingUses =
        Moveset[iMove][0].initialUses;
  }
};

void Character::addStatus(Status* Effect){
  //If input is a null pointer, do nothing.
  if (Effect == nullptr) {
    return;
  }
  //Create new array with size numOfEffects+1
  Status** newStatusEffect = new Status*[numberOfEffects + 1];
  // Add pointers to array
  for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
    newStatusEffect[iStatus] = StatusEffect[iStatus];
  }
  newStatusEffect[numberOfEffects] = Effect;
  // Free old array
  delete StatusEffect;
  StatusEffect = newStatusEffect;
  // increment numOfEffects
  numberOfEffects++;
};

void Character::removeStatus(int effectIndex){
  //If the index is invalid, do nothing.
  if (effectIndex < 0 || effectIndex >= numberOfEffects) {
    return;
  }
  delete StatusEffect[effectIndex];
  StatusEffect[effectIndex] = nullptr;
  
  // Create new array with size numOfEffects-1
  Status** newStatusEffect = new Status*[numberOfEffects - 1];
  // Add pointers to array
  int iStatus2 = 0;
  for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
    if (iStatus != effectIndex) {
      newStatusEffect[iStatus2] = StatusEffect[iStatus];
      iStatus2++;
    }
  }
  // Free old array
  delete StatusEffect;
  StatusEffect = newStatusEffect;
  // decrement numOfEffects
  numberOfEffects--;
};

bool Character::removeStatus(string effectType){
  //Find all Statuses with type == effectType
  int n = 0;
  for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
    if (effectType == StatusEffect[iStatus][0].statusType) {
      delete StatusEffect[iStatus];
      StatusEffect[iStatus] = nullptr;
      n++;
    }
  }

  if (n == numberOfEffects) {
    numberOfEffects = 0;
    delete StatusEffect;
    StatusEffect = nullptr;
    return true;
  }
  //If all Status effects are to be removed, clear the entire array.

  //Create new array with size numOfEffects-n
  Status** newStatusEffect = new Status*[numberOfEffects - n];
  //Add pointers to array
  int iStatus2 = 0;
  for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
    if (StatusEffect[iStatus]!= nullptr) {
      newStatusEffect[iStatus2] = StatusEffect[iStatus];
      iStatus2++;
    }
  }
  // Free old array
  delete StatusEffect;
  StatusEffect = newStatusEffect;
  // decrement numOfEffects
  numberOfEffects-=n;
  return n > 0;
  };