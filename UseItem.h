#ifndef USEITEM_H
#define USEITEM_H

#include "Item.h"
#include "Action.h"
#include "Character.h"
#include "Battle.h"
#include "Status.h"
#include <string>

using namespace std;

// Class definition for UseItem class
class UseItem : public Action{
    public:
     // Declares variables
     string type;
     Item* item;
     int quantity;
     // Declares functions
     UseItem();
     UseItem(string name, string type, int quantity, Character* Target, Character* Actor);
     ~UseItem();
};

// Class definition for UseCureItem class
class UseCureItem : public UseItem {
 private:
  // Declares variables
  Status* statusToRemove;
 public:
  // Declares function
  void Execute(string name, Character* Target, Character* Actor);
};

// Class definition for UseHealItem class
class UseHealItem: public UseItem {
  private:
   // Declares variables
   int healAmount;
   int cooldown;
  public:
   // Declares function
   //void getVal(Battle* currentTurn)
   void Execute(string name, Character* Target, Character* Actor);
};

// Class definition for UseStatusItem class
class UseStatusItem : public UseItem {
 private:
  // Declares variables
  Status* StatusEffect;
 public:
  // Declares function
  void Execute(string name, Character* Target, Character* Actor);
};

#endif //USEITEM_H