#include <iostream>

#include "Attack_Move.h"
#include "Character.h"
#include "Heal_Move.h"

int main() {
  Character *a, *b;
  a = new Character(); //need to fill in details and implement automatic test checking
  b = new Character();

  Attack_Move* c;
  c = new Attack_Move();

  Heal_Move* d;
  d = new Heal_Move();

  c->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  d->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  return 0;
}