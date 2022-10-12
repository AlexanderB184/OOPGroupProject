#include <string>
using namespace std;



#ifndef CHARACTER_H
#define CHARACTER_H
#include "Status.h"
#include "Move.h"

class Status;

class Move;

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
  //Applies the effect of all Status effects a character has onto that character

  void resetCharacter();
  //Resets all the stats of a character

  void addStatus(Status* Effect);
  //Adds a status to the character

  void removeStatus(int effectIndex);
  bool removeStatus(string effectType);
  // Removes a status from the character, either by specifying the index of the
  // status to be removed or the type
};

#endif