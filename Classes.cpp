#include <string>
#include <iostream>
using namespace std;

class Controller {
  Character* Characters;
  Character* ActiveCharacter;
  Item* Inventory;
  Action* ActionOptions;

  Action*, Character* GetAction();  // virtual function, gets the move that will
                                    // be executed in the current turn
  void generateOptions(); //Creates Action Options by 
  //combining Use Item Actions with the Active Characters Moveset

  Controller();
  ~Controller();
};

class HumanPlayer : public Controller {
  Action*, Character* GetAction(); //Gets Options by asking player
  void DisplayOptions();
  HumanPlayer();
  ~HumanPlayer();
};

class ComputerPlayer: public Controller {
  int Difficulty; //Only necessary if computer isn't purely random.
  Action*, Character* GetAction(); //Computer decides moves, probably randomly.
  ComputerPlayer();
  ComputerPlayer(int Difficulty); 
  ~ComputerPlayer();
}

class Character {
  int _HP;
  int _MaxHP;
  string _Name;
  int _XP;
  Status* _StatusEffects;
  Move* _Moveset;

  //Stats
  int BaseAttack;
  int BaseDefence;
  int BaseSpeed; //Effects dodge/miss chance
  int BaseHeal;


  void ApplyStatus(); //Applies the effect of all status effects this character has

  Character();
  Character(int MaxHP, string Name, Move* Moveset);

  ~Character();
};

class Status {
  int _Duration;      // Number of turns remaining
  string StatusType;  // Specifically for cure items,
  // so they know which status effect must be removed, also to prevent duplicate
  // status effects
  string Type;
  void Apply();  // Applies the effect of the status effect, e.g. burn status
                 // effect would subtract health
  Status();
};

class BurnEffect: public Status {
  int _DamageRate;
  BurnEffect();
  BurnEffect(int Duration, int DamageRate);
  void Apply();
};

class RegenEffect: public Status {
  int _HealRate;
  RegenEffect();
  RegenEffect(int Duration, int HealRate);
  void Apply();
}

class StunEffect: public Status {
  int ChanceToMissTurn;
  StunEffect();
  StunEffect(int Duration, int ChanceToMissTurn);
  void Apply();
};

class Action {
  string Description; //Explains what move will do, i.e. Damage Amount, Heal Amount etc.
  void Execute(Character* actor, Character* target);  // Purely Virtual Function

  //All Actions will need to parse the actor (character performing the action) 
  //and target when being execute, so that the actions know whose stats to read and 
  //who to apply the action to
  //Actor and Target will not be stored in the Action object so that the action object can be more general
  //And used by any character on any other character.
  Action();
  ~Action();
};

class Move: public Action {
  string Type;
  int usesLeft;
  int _usesAtStartOfBattle;

  Move();

  ~Move();
};

class AttackMove: public Move {
  int Damage;
  int Accuracy;

  void Execute(Character* attacker, Character* target);

  AttackMove();
  AttackMove(int Damage, int Accuracy, int MaxUses);
};

class HealMove: public Move {
  int HealAmount;
  int Cooldown;

  void Execute(Character* Healer, Character* Healer); //Heal Move is applied to self

  HealMove();
  HealMove(int HealAmount, int Cooldown, int MaxUses);
};

class StatusMove: public Move {
  Status* StatusEffect;
  int Duration;

  void Execute(Character* Attacker, Character* Target);

  StatusMove();
  StatusMove(Status* StatusEffect, int Duration, int MaxUses);
  ~StatusMove();
};

class SpecialAttack : public Move {
    int Damage;
    int Accuracy;
    Status* StatusEffect;
    int Duration;

    void Execute(Character* Attacker, Character* Target);
    SpecialAttack();
    SpecialAttack(int Damage, int Accuracy, int Duration, Status* StatusEffect, int MaxUses);
    ~SpecialAttack();
};

class Item {
  string Name;
  int Uses;
  Action* ItemAction;

  Item();
  ~Item();
};

class UseItem : public Action {
  Item* ItemUsed;
  UseItem();
  ~UseItem();
};

class UseHealItem : public UseItem {
  int Heal;
  UseHealItem();
  ~UseHealItem();
  void Execute(Character* Attacker, Character* Target);
};

class UseRemoveStatusItem : public UseItem { //Maybe rename to UseCureItem
  Status* StatusToRemove;
  UseRemoveStatusItem();
  ~UseRemoveStatusItem();
  void Execute(Character* Attacker, Character* Target);
};

class UseStatusItem : public UseItem {
  Status* StatusEffect;
  UseStatusItem();
  ~UseStatusItem();
  void Execute(Character* Attacker, Character* Target);
};

class Battle {
  Controller* Players[2];
  int CurrentTurn;  // Either the first players turn (0) or the second players
                    // turn (1)
  void Turn();
  // Turn could be implemented as follows
  // 1. Start Turn;
  // 2. Players[CurrentTurn].ActiveCharacter.ApplyStatusEffects(); 
        //Possible would need to be applied to all their characters
  // 3. Action, Target = Players[CurrentTurn].getAction();
  // 4. Action.execute(Player[CurrentTurn].ActiveCharacter, Target);
  // 5. CurrentTurn = not Current Turn;
  // 6. End Turn;
  Battle();
  Battle(Controller* Players[2]);
  ~Battle();
};