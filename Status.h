#ifndef STATUS_H
#define STATUS_H

#include <string>
#include "Character.h"
using namespace std;

class Character;

class Status {
 public:
  virtual Status* clone() = 0;

  int duration;
  string statusType;
  virtual void Apply(Character* Target) = 0;
};

class BurnEffect: public Status {
    public:
    virtual BurnEffect* clone();

     int damageRate;
     BurnEffect();
     BurnEffect(int _damageRate, int _duration);
     void Apply(Character* Target);
};

class RegenEffect: public Status {
    public:
    virtual RegenEffect* clone();

     int healRate;
     RegenEffect();
     RegenEffect(int _healRate, int _duration);
     void Apply(Character* Target);
};

class StunEffect: public Status {
    public:
    virtual StunEffect* clone();

     int chanceToMissTurn;
     StunEffect();
     StunEffect(int _chanceToMissTurn, int _duration);
     void Apply(Character* Target);
};

#endif