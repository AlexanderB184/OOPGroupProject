#include <string>
using namespace std;

#include "Character.h"

Character::Character() {
  Name = "";
  HP = 100;
  maxHP = 100;
  baseAtt = 20;
  baseDef = 20;
  baseSpeed = 20;
  baseHeal = 20;
  // Status* StatusEffect;
  // int numberOfEffects;
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
  // Status* StatusEffect;
  // int numberOfEffects;
  // Move* Moveset;
  // int numberOfMoves;
  missNextTurn = false;
  dead = false;
};

Character::~Character(){
    // Delete Moveset and Status
};

void Character::ApplyStatus() { 
//for (int i = 0; i < numberOfEffects;i++) {
//  StatusEffects[i].apply(this);
//if (HP > maxHP) {
//    HP = maxHP;
//}
//else if (HP <= 0) {
//    HP = 0;
//    dead = true;
//}
//}
};