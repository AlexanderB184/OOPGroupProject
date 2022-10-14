#ifndef GAMESAVE_H
#define GAMESAVE_H

#include "Battle.h"
#include "Controller.h"
#include "ComputerController.h"
#include "HumanController.h"
#include "Character.h"

#include <string>
#include <iostream>

class GameSave {
 public:
  Character** PossibleCharacters;
  int nPossibleCharacters;
  Move** PossibleMoves;
  int nPossibleMoves;
  Item** PossibleItems;
  int nPossibleItems;

  Battle OngoingBattle;
  Controller** Players;
  Character* Character1;
  Character* Character2;

  GameSave();
  ~GameSave();

  Character* selectCharacter();

  bool loadFromFile(string filename);
  bool saveToFile(string filename);
};


#endif