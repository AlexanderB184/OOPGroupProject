#ifndef STATUS_H
#define STATUS_H

#include <string>

#include "Character.h"
using namespace std;

class Character;

class Status {
 public:
  virtual void Apply(Character* Target) = 0;
  virtual Status* clone() = 0;

  int duration;
  string statusType;
};

class BurnEffect: public Status {
    public:
     BurnEffect();
     BurnEffect(int _damageRate, int _duration);
     void Apply(Character* Target);
     virtual BurnEffect* clone();

     int damageRate;
};

class RegenEffect: public Status {
    public:
     RegenEffect();
     RegenEffect(int _healRate, int _duration);
     void Apply(Character* Target);
     virtual RegenEffect* clone();

     int healRate;
};

class StunEffect: public Status {
    public:
     StunEffect();
     StunEffect(int _chanceToMissTurn, int _duration);
     void Apply(Character* Target);
     virtual StunEffect* clone();

     int chanceToMissTurn;
};

#endif