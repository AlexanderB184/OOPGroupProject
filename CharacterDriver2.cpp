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
    Character TestCharacter =
        Character("Test Dummy", 100, 50, 50, 50, 50, nullptr, 0);
    // Test 1
    BurnEffect *Status1 = new BurnEffect();
    TestCharacter.addStatus(Status1);
    if (TestCharacter.StatusEffect[0][0].statusType != "Burn") {
      cout << "Test 1 Failed" << endl;
    }
    printStatus(TestCharacter);
    // Test 2
    RegenEffect *Status2 = new RegenEffect();
    TestCharacter.addStatus(Status2);
    if (TestCharacter.StatusEffect[1][0].statusType != "Regen") {
      cout << "Test 2 Failed" << endl;
    }
    printStatus(TestCharacter);
    // Test 3
    StunEffect *Status3 = new StunEffect();
    TestCharacter.addStatus(Status3);
    if (TestCharacter.StatusEffect[2][0].statusType != "Stun") {
      cout << "Test 3 Failed" << endl;
    }
    printStatus(TestCharacter);
    // Test 4
    TestCharacter.removeStatus(1);
    if (TestCharacter.StatusEffect[1][0].statusType == "Regen") {
      cout << "Test 4 Failed" << endl;
    }
    printStatus(TestCharacter);
    // Test 5
    TestCharacter.removeStatus(4);
    printStatus(TestCharacter);
    // Test 6
    TestCharacter.removeStatus("Burn");
    if (TestCharacter.StatusEffect[0][0].statusType == "Burn") {
      cout << "Test 6 Failed" << endl;
    }
    printStatus(TestCharacter);
    // Test 7
    TestCharacter.removeStatus("Fake");
    printStatus(TestCharacter);
  }

  return 0;
}