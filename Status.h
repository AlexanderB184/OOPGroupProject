#ifndef STATUS_H
#define STATUS_H

#include <string>

#include "Character.h"
using namespace std;

class Character;

class Status {
 public:
  //Virtual function applies status to character it afflicts, different implementation for different status effects
  virtual void Apply(Character* Target) = 0;
  //Clone status effect, different for different effects
  virtual Status* clone() = 0;

  int duration;
  string statusType;
};

class BurnEffect: public Status {
    public:
     BurnEffect();
     BurnEffect(int _damageRate, int _duration);
     //Burn Effect takes health away from character it afflicts
     void Apply(Character* Target);
     //clone clones status effect
     virtual BurnEffect* clone();

     int damageRate;
};

class RegenEffect: public Status {
    public:
     RegenEffect();
     RegenEffect(int _healRate, int _duration);
     //Regen Effect adds health to character it afflicts
     void Apply(Character* Target);
     //clone clones status effect
     virtual RegenEffect* clone();

     int healRate;
};

class StunEffect: public Status {
    public:
     StunEffect();
     StunEffect(int _chanceToMissTurn, int _duration);
     //Stun effect has a chance to make character miss next turn
     void Apply(Character* Target);
     //clone clones status effect
     virtual StunEffect* clone();

     int chanceToMissTurn;
};

#endif