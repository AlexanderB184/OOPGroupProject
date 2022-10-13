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
#include "Heal_Move.h"
#include "Item.h"
#include "UseItem.h"

int main(void) {
  {

    Character* C1 = new Character("Bob");
    Character* C2 = new Character("Mark");
    HumanController* player = new HumanController(C1, nullptr, 0);
    ComputerController* enemy = new ComputerController(C2,nullptr,0);
    Controller** players = new Controller*[2];
    players[0] = player;
    players[1] = enemy;
    Battle battle = Battle(players, 0);

    battle.initBattle();
    battle.runBattle();

  }

  return 0;
}