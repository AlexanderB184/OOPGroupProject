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
  
  Move ** movesList = new Move*[4];
  movesList[0] = new Attack_Move("basic_attack", 10, 10, 70);
  movesList[1] = new Heal_Move("basic_heal", 7, 20, 2);
  movesList[2] = new Status_Move("generic_status", 5, nullptr, "a_status_condition", 100);
  movesList[3] = new Special_Attack_Move("basic_special_attack", 2, 12, 100, nullptr, "a_status_condition", 50);

  Character *a, *b;
  a = new Character("Char1", 100, 20, 20, 50, 10, movesList, 4);
  b = new Character("Char2", 100, 20, 12, 30, 10, movesList, 4);

  // test 1
  movesList[0]->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  movesList[1]->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl << std::endl;

  // test 2
  movesList[0]->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  movesList[0]->Execute(a, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  movesList[1]->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl;

  movesList[1]->Execute(b, b);

  std::cout << b->HP << "/" << b->maxHP << std::endl << std::endl;

  // test 3
  movesList[2]->Execute(a, b);
  std::cout << std::endl;

  // test 4
  movesList[3]->Execute(a, b);

  return 0;
}