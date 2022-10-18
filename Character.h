#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H
#include "Move.h"
#include "Status.h"

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

  // Constructor takes in the stats and moves and creates a charactor
  Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,
            int _baseSpeed, int _baseHeal, Move** Moveset, int _numberOfMoves);

  // Constructor takes in stats and a list of possible moves as well as which of
  // those moves the character will use
  Character(string _Name, int _maxHP, int _baseAtt, int _baseDef,
            int _baseSpeed, int _baseHeal, Move**, int[], int _numberOfMoves);

  // Decontructor clears the memory
  ~Character();

  // Clone function creates a new identical character
  Character* clone();

  void ApplyStatus();
  // Applies the effect of all Status effects a character has onto that
  // character

  void resetCharacter();
  // Resets all the stats of a character

  void addStatus(Status* Effect);
  // Adds a status to the character

  void removeStatus(int effectIndex);
  bool removeStatus(string effectType);
  // Removes a status from the character, either by specifying the index of the
  // status to be removed or the type
};

#endif