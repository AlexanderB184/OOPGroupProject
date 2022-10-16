#include "Character.h"

#ifndef ACTION_H
#define ACTION_H
#include <string>

class Character;

class Action {
 public:
  Action();
  virtual void Execute(Character* Actor, Character* Target) = 0;
  virtual Action* clone() = 0;
  std::string name;
  std::string description;
};
#endif