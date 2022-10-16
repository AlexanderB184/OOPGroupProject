#include <ctime>
#include <iostream>

#include "Attack_Move.h"
#include "Character.h"
#include "Heal_Move.h"
#include "Special_Attack_Move.h"
#include "Status_Move.h"

int main() {
  srand(time(NULL));  // randomize seed
  // due to the randomness involved, these tests have to be checked by a human

  Attack_Move* c;
  c = new Attack_Move("basic attack", 10, 10, 70);

  Heal_Move* d;
  d = new Heal_Move("basic heal", 7, 20, 2);

  Status_Move* e;
  e = new Status_Move("generic status", 5, nullptr, "a status condition", 100);

  Special_Attack_Move* f;
  f = new Special_Attack_Move("basic special attack", 2, 12, 100, nullptr,
                              "a status condition", 50);

  Character *a, *b;
  a = new Character("Char1", 100, 20, 20, 50, 10, nullptr, 4);
  b = new Character("Char2", 100, 20, 12, 30, 10, nullptr, 4);

  // test 1
  c->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  d->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl << std::endl;

  // test 2
  c->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  c->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  d->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  d->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl << std::endl;

  // test 3
  e->Execute(a, b);
  std::cout << std::endl;

  // test 4
  f->Execute(a, b);

  return 0;
}