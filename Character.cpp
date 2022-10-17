#include <iostream>
#include <string>
using namespace std;
#include "Attack_Move.h"
#include "Character.h"
#include "GameSave.h"
#include "Heal_Move.h"
#include "Move.h"
#include "Status.h"

Character::Character(string characterName) {
  if (characterName == "Bob") {
    // Ninja
    Name = "Bob";
    HP = 50;
    maxHP = 50;
    baseAtt = 75;
    baseDef = 40;
    baseSpeed = 100;
    baseHeal = 20;
    StatusEffect = nullptr;
    numberOfEffects = 0;
    missNextTurn = false;
    dead = false;
    Moveset = new Move*[3];
    Moveset[0] = new Attack_Move("Stab", 1000, 25, 80);
    Moveset[1] = new Attack_Move("Throw Knife", 1, 100, 20);
    Moveset[2] = new Heal_Move("Crack Open a cold One", 6, 30);
    numberOfMoves = 3;
  } else if (characterName == "Jane") {
    // Tank
    Name = "Jane";
    HP = 250;
    maxHP = 250;
    baseAtt = 45;
    baseDef = 100;
    baseSpeed = 20;
    baseHeal = 40;
    StatusEffect = nullptr;
    numberOfEffects = 0;
    missNextTurn = false;
    dead = false;
    Moveset = new Move*[3];
    Moveset[0] = new Attack_Move("Slap", 1000, 30, 80);
    Moveset[1] = new Attack_Move("Body Slam", 5, 50, 20);
    Moveset[2] = new Heal_Move("Inject Substances", 6, 30);
    numberOfMoves = 3;
  } else if (characterName == "T") {
    // Healer
    Name = "T";
    HP = 100;
    maxHP = 100;
    baseAtt = 25;
    baseDef = 70;
    baseSpeed = 60;
    baseHeal = 100;
    StatusEffect = nullptr;
    numberOfEffects = 0;
    missNextTurn = false;
    dead = false;
    Moveset = new Move*[2];
    Moveset[0] = new Heal_Move("T", 1, 100);
    Moveset[1] = new Heal_Move("t", 100, 30);
    numberOfMoves = 2;
  } else if (characterName == "Mark") {
    // Average Joe
    Name = "Mark";
    HP = 100;
    maxHP = 100;
    baseAtt = 50;
    baseDef = 50;
    baseSpeed = 50;
    baseHeal = 50;
    StatusEffect = nullptr;
    numberOfEffects = 0;
    missNextTurn = false;
    dead = false;
    Moveset = new Move*[2];
    Moveset[0] = new Attack_Move("Average attack", 1000, 30, 85);
    Moveset[1] = new Heal_Move("Average heal", 1000, 35);
    numberOfMoves = 2;
  }
}

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

Character::Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,
                     int _baseSpeed, int _baseHeal, Move** _Moveset,
                     int _numberOfMoves) {
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

Character::Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,
                     int _baseSpeed, int _baseHeal, Move** PossibleMoves,
                     int _Moveset[], int _numberOfMoves) {
  Name = _Name;
  HP = _maxHP;
  maxHP = _maxHP;
  baseAtt = _baseAtt;
  baseDef = _baseDef;
  baseSpeed = _baseSpeed;
  baseHeal = _baseHeal;
  StatusEffect = nullptr;
  numberOfEffects = 0;
  numberOfMoves = _numberOfMoves;
  Moveset = new Move*[numberOfMoves];
  for (int iMove = 0; iMove < numberOfMoves; iMove++) {
    Moveset[iMove] = PossibleMoves[_Moveset[iMove]][0].clone();
  }
  missNextTurn = false;
  dead = false;
};

Character::~Character() {
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
  for (int i = 0; i < numberOfEffects; i++) {
    StatusEffect[i][0].Apply(this);
    if (StatusEffect[i][0].duration <= 0) {
      removeStatus(i);
      i--;
    }
  }
  if (HP > maxHP) {
    HP = maxHP;
  } else if (HP <= 0) {
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

    Moveset[iMove][0].remainingUses = Moveset[iMove][0].initialUses;
  }
};

void Character::addStatus(Status* Effect) {
  // If input is a null pointer, do nothing.
  if (Effect == nullptr) {
    return;
  }
  // Create new array with size numOfEffects+1
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

void Character::removeStatus(int effectIndex) {
  // If the index is invalid, do nothing.
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

bool Character::removeStatus(string effectType) {
  // Find all Statuses with type == effectType
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
  // If all Status effects are to be removed, clear the entire array.

  // Create new array with size numOfEffects-n
  Status** newStatusEffect = new Status*[numberOfEffects - n];
  // Add pointers to array
  int iStatus2 = 0;
  for (int iStatus = 0; iStatus < numberOfEffects; iStatus++) {
    if (StatusEffect[iStatus] != nullptr) {
      newStatusEffect[iStatus2] = StatusEffect[iStatus];
      iStatus2++;
    }
  }
  // Free old array
  delete StatusEffect;
  StatusEffect = newStatusEffect;
  // decrement numOfEffects
  numberOfEffects -= n;
  return n > 0;
};

Character* Character::clone() {
  Move** clonedMoveset = new Move*[numberOfMoves];
  for (int iMove = 0; iMove < numberOfMoves; iMove++) {
    clonedMoveset[iMove] = Moveset[iMove][0].clone();
  }

  Character* clonedCharacter =
      new Character(Name, maxHP, baseAtt, baseDef, baseSpeed, baseHeal,
                    clonedMoveset, numberOfMoves);
  return clonedCharacter;
};