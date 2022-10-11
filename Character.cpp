#include <string>
using namespace std;
#include "Status.h"
#include "Character.h"

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
  // Move* Moveset;
  // int numberOfMoves;
  missNextTurn = false;
  dead = false;
};

Character::Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,int _baseSpeed, int _baseHeal, string Moveset) {
  Name = _Name;
  HP = _maxHP;
  maxHP = _maxHP;
  baseAtt = _baseAtt;
  baseDef = _baseDef;
  baseSpeed = _baseSpeed;
  baseHeal = _baseHeal;
  StatusEffect = nullptr;
  numberOfEffects = 0;
  // Move* Moveset;
  // int numberOfMoves;
  missNextTurn = false;
  dead = false;
};

Character::~Character(){
    // Delete Moveset and Status
};

void Character::ApplyStatus() { 
for (int i = 0; i < numberOfEffects;i++) {
  StatusEffect[i][0].Apply(this);
}
if (HP > maxHP) {
    HP = maxHP;
}
else if (HP <= 0) {
    HP = 0;
    dead = true;
}
};