#include <string>
using namespace std;



#ifndef CHARACTER_H
#define CHARACTER_H
#include "Status.h"
class Status;

class Move {
  public:
  int remainingUses;
  int initialUses;
};

class Character {
 public:
  string Name;
  int HP;
  int maxHP;
  int baseAtt;
  int baseDef;
  int baseSpeed;
  int baseHeal;
  Status** StatusEffect;
  int numberOfEffects;
  Move** Moveset;
  int numberOfMoves;
  bool missNextTurn;
  bool dead;
  Character();
  Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,
            int _baseSpeed, int _baseHeal, Move** Moveset, int _numberOfMoves);
  ~Character();
  void ApplyStatus();
  void resetCharacter();

  void addStatus(Status* Effect);
  void removeStatus(int effectIndex);
  void removeStatus(string effectType);
};

#endif