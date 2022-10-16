#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

#include "Character.h"
#include "Status.h"
using namespace std;

void printStatus(Character c) {
  cout << "-------" << endl;
  for (int i = 0; i < c.numberOfEffects; i++) {
    cout << c.StatusEffect[i][0].statusType << endl;
  }
}

int main(void) {
  {
    Move *movie = new Move();
    movie[0].initialUses = 10;
    movie[0].remainingUses = 10;
    Character TestCharacter =
        Character("Test Dummy", 100, 50, 50, 50, 50, &movie, 1);

    // Test 1
    TestCharacter.resetCharacter();

    // Test 2

    TestCharacter.Moveset[0][0].remainingUses = 0;

    TestCharacter.resetCharacter();

    if (TestCharacter.Moveset[0][0].remainingUses !=
        TestCharacter.Moveset[0][0].initialUses) {
      cout << "Test 2 Failed" << endl;
    }
    // test 3
    TestCharacter.HP = 0;
    TestCharacter.dead = true;

    TestCharacter.resetCharacter();

    if (TestCharacter.HP != TestCharacter.maxHP || TestCharacter.dead) {
      cout << "Test 3 Failed" << endl;
    }
    // test 4
    BurnEffect *effect = new BurnEffect();
    TestCharacter.addStatus(effect);
    TestCharacter.resetCharacter();
    if (TestCharacter.numberOfEffects != 0) {
      cout << "Test 4 Failed" << endl;
    }
    // Test 5
    TestCharacter.missNextTurn = true;
    TestCharacter.resetCharacter();
    if (TestCharacter.missNextTurn) {
      cout << "Test 5 Failed" << endl;
    }
  }

  return 0;
}