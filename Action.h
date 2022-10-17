#include "Character.h"

#ifndef ACTION_H
#define ACTION_H
#include <string>

class Character;

class Action {
 public:
  virtual void Execute(Character* Actor, Character* Target) = 0;
  // Executes the action with the Actor being the user of the move and the Target
  // being the opponent
  virtual Action* clone() = 0;  // Makes a clone object
  std::string name;
  std::string description;
};
#endif