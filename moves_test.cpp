#include <ctime>
#include <iostream>

#include "Attack_Move.h"
#include "Character.h"
#include "Heal_Move.h"

int main() {
  srand(time(NULL));  // randomize seed
  // due to the randomness involved, these tests have to be checked by a human

  Attack_Move* c;
  c = new Attack_Move("basic attack", 10, 10, 70);

  Heal_Move* d;
  d = new Heal_Move("basic heal", 7, 20, 2);

  Character *a, *b;
  a = new Character("Char1", 100, 20, 20, 50, 10, "basic attack, basic heal");
  b = new Character("Char2", 100, 20, 12, 30, 10, "basic attack, basic heal");

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

  return 0;
}