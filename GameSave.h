#ifndef GAMESAVE_H
#define GAMESAVE_H

#include <iostream>
#include <string>

#include "Battle.h"
#include "Character.h"
#include "ComputerController.h"
#include "Controller.h"
#include "HumanController.h"

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

  Character* loadFromFile(string filename);
  bool saveToFile(string filename, string);
};

#endif