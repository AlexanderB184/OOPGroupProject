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
  // Prefab Characters, Moves and Items
  Character** PossibleCharacters;
  int nPossibleCharacters;
  Move** PossibleMoves;
  int nPossibleMoves;
  Item** PossibleItems;
  int nPossibleItems;

  GameSave();   // Constructor creates the prefab objects
  ~GameSave();  // Deconstructer deletes the prefab objects

  // Asks the user to select a character and returns the character they select
  Character* selectCharacter();

  // Loads a game save from a file and returns the character saved in the file
  Character* loadFromFile(string filename);

  // Saves the current character to file
  bool saveToFile(string filename, string);
};

#endif