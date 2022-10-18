#include "Character.h"
#include "Status.h"
#include "Action.h"


#ifndef USEITEM_H
#define USEITEM_H
#include "Item.h"
#include <string>



using namespace std;

// Class definition for UseItem class
class UseItem : public Action {
 public:
  // Declares variables
  string type;
  Item* item;
  int quantity;
  virtual UseItem* clone() = 0;
};

// Class definition for UseCureItem class
class UseCureItem : public UseItem {
 private:
  // Declares variables
  string statusToRemove;

 public:
  // Declares function
  UseCureItem(string, string, int);
  void Execute(Character* Target, Character* Actor);
  UseCureItem* clone();
};

// Class definition for UseHealItem class
class UseHealItem : public UseItem {
 private:
  // Declares variable
  int healAmount;

 public:
  // Declares function
  UseHealItem(string,int, int);
  void Execute(Character* Target, Character* Actor);
  UseHealItem* clone();
};

// Class definition for UseStatusItem class
class UseStatusItem : public UseItem {
 private:
  // Declares variables
  Status* statusEffect;

 public:
  // Declares function
  UseStatusItem(string, Status* status, int);
  void Execute(Character* Target, Character* Actor);
  UseStatusItem* clone();
};

#endif  // USEITEM_H