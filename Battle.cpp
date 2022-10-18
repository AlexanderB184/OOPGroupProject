#include "Battle.h"

#include <iostream>
#include <string>

using namespace std;

Battle::Battle() {
  players = nullptr;
  currentTurn = 0;
};

Battle::Battle(Controller** _players, int _currentTurn) {
  players = _players;
  currentTurn = _currentTurn;
};

Battle::~Battle() {
  if (players != nullptr) {
    delete players;
  }
};

void Battle::initBattle() {
  // Resets Variables to start new battle
  currentTurn = 0;
  turnCounter = 1;
  players[0][0].character[0].resetCharacter();
  players[1][0].character[0].resetCharacter();
};

void Battle::Turn() {
  // These pointers exist for clarity
  // They do not need to be free since they point to already allocated memory
  // managed by a different object
  Controller* activePlayer = players[currentTurn];
  Controller* opposingPlayer = players[!currentTurn];

  Character* activeCharacter = activePlayer[0].character;
  Character* opposingCharacter = opposingPlayer[0].character;

  cout << "=========================" << endl;
  cout << "Beginning of Player " << currentTurn + 1 << "'s Turn" << endl;
  cout << "=========================" << endl;
  cout << activeCharacter[0].Name << endl;
  cout << activeCharacter[0].HP << " HP" << endl;
  cout << "=========================" << endl;

  // Apply Status Effects
  cout << "Applying Status Effects" << endl;
  activeCharacter[0].ApplyStatus();

  // Text to indicate that game is progressing, (game turns can look identical)
  cout << "Current Turn: " << turnCounter << endl;
  // Only runs on second player's turn
  if (currentTurn == 1){
    turnCounter++;
  }

  // If the player is dead or has flag "missNextTurn" then their turn is
  // terminated here.
  if (activeCharacter[0].dead) {
    cout << "Turn terminated, Character Died" << endl;
    return;
  }
  if (activeCharacter[0].missNextTurn) {
    cout << "Turn terminated, Character Stunned" << endl;
    return;
  }

  // Getting the players action
  // Commented out for now, seems like they use up a lot of screen room
  //cout << "Generating Options" << endl;
  activePlayer[0].generateOptions();
  //cout << "Getting Action" << endl;
  Action* selectedAction = activePlayer[0].getAction();

  // Executing the players action
  cout << "Executing Action" << endl;
  selectedAction[0].Execute(activeCharacter, opposingCharacter);
  // Swapping whose turn it is
  currentTurn = !currentTurn;
  cout << "End of turn" << endl;
};

bool Battle::runBattle() {
  // While both player's characters are alive keep looping Turn()
  while (!players[0][0].character[0].dead && !players[1][0].character[0].dead) {
    Turn();
  }
  // Once the loop has broken one players character has died, i.e. a player has
  // lost Return if the losing character is player 1
  return !players[0][0].character[0].dead;
}