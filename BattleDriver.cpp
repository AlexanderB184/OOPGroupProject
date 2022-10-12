#include "Status.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

void printStatus(Character c) {
  cout << "-------" << endl;
  for (int i = 0; i < c.numberOfEffects; i++) {
    cout << c.StatusEffect[i][0].statusType << endl;
  }
}

#include "Status.h"
#include "Battle.h"
#include "Character.h"
#include "ComputerController.h"
#include "HumanController.h"
#include "Action.h"
#include "Move.h"
#include "Attack_Move.h"
#include "Item.h"
#include "UseItem.h"

int main(void) {
  {

    //Replace with propper moves
    Move** movie = new Move* [2];
    movie[0] = new Attack_Move("Slash", 20, 20, 75);
    movie[1] = new Attack_Move("Shoot", 5, 50, 60);
    Move** movie2 = new Move* [1];
    movie2[0] = new Attack_Move("Slash", 20, 20, 75);

    Character* C1 = new Character("Test Dummy", 100, 50, 50, 50, 50, movie, 2);
    Character* C2 = new Character("Test Dummy2", 100, 50, 50, 50, 50, movie2, 1);
    HumanController* player = new HumanController(C1, nullptr, 0);
    ComputerController* enemy = new ComputerController(C2,nullptr,0);
    Controller** players = new Controller*[2];
    players[0] = player;
    players[1] = enemy;
    Battle battle = Battle(players, 0);

    //Test 1
    battle.initBattle();
    cout << "Test 1 Passed" << endl;
    // Test 2
    battle.Turn();
    cout << "Test 2 Passed" << endl;
    // Test 3
    battle.Turn();
    cout << "Test 3 Passed" << endl;
    // Test 4
    battle.initBattle();
    cout << "Test 4 Passed" << endl;
    // Test 5
    battle.runBattle();
  }

  return 0;
}