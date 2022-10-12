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
#include "Controller.h"
#include "ComputerController.h"
#include "HumanController.h"

int main(void) {
  {

    //Replace with propper moves
    Move * movie = new  Move();
      movie[0].initialUses = 10;
      movie[0].remainingUses = 10;
      Move * movie2 = new  Move();
      movie[0].initialUses = 10;
      movie[0].remainingUses = 10;

    Character* C1 = new Character("Test Dummy", 100, 50, 50, 50, 50, &movie, 1);
    Character* C2 = new Character("Test Dummy", 100, 50, 50, 50, 50, &movie2, 1);
    HumanController* player = new HumanController(C1, nullptr, 0);
    ComputerController* enemy = new ComputerController(C2,nullptr,0);
    Controller** players = new Controller*[2];
    players[0] = player;
    players[1] = enemy;
    Battle battle = Battle(players, 0);

    //Test 1
    battle.initBattle();

    //Test 2
    battle.Turn();

    //Test 3
    battle.Turn();

    //Test 4
    battle.initBattle();

    //Test 5
    battle.runBattle();
  }

  return 0;
}