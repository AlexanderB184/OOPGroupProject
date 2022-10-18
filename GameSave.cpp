#include "GameSave.h"

#include <fstream>

#include "Attack_Move.h"
#include "Heal_Move.h"
#include "Status_Move.h"

GameSave::GameSave() {
  // Create list of Prefab Moves
  nPossibleMoves = 5;
  PossibleMoves = new Move*[nPossibleMoves];
  PossibleMoves[0] = new Attack_Move("Stab", 1000, 35, 85);
  PossibleMoves[1] = new Attack_Move("Slash", 1000, 20, 90);
  PossibleMoves[2] = new Attack_Move("Shoot", 6, 65, 60);
  PossibleMoves[3] = new Heal_Move("Meditate", 5, 50);
  Status* statusEffect = new BurnEffect(10, 10);
  PossibleMoves[4] = new Status_Move("Burn", 5, statusEffect, "Burn", 100);
  // Create list of Prefab Characters
  nPossibleCharacters = 4;
  PossibleCharacters = new Character*[nPossibleCharacters];
  int Moves1[3] = {0, 1, 3};
  PossibleCharacters[0] =
      new Character("Bob", 50, 75, 40, 100, 20, PossibleMoves, Moves1, 3);
  int Moves2[3] = {1, 2, 3};
  PossibleCharacters[1] =
      new Character("Jane", 200, 40, 75, 30, 50, PossibleMoves, Moves2, 3);
  int Moves3[3] = {1, 4, 3};
  PossibleCharacters[2] =
      new Character("T", 50, 75, 40, 100, 20, PossibleMoves, Moves3, 3);
  int Moves4[3] = {0, 2, 3};
  PossibleCharacters[3] =
      new Character("Mark", 100, 50, 50, 50, 50, PossibleMoves, Moves4, 3);
  // Prefab Items
  nPossibleItemActions = 3;
  PossibleItemActions = new UseItem*[3];
  PossibleItemActions[0] = new UseCureItem("Burn", 1);
  Status* statusEffect2 = new RegenEffect(10, 10);
  PossibleItemActions[1] = new UseStatusItem(statusEffect2, 1);
  PossibleItemActions[2] = new UseHealItem(50, 1);
  nPossibleItems = 3;
  PossibleItems = new Item*[3];
  PossibleItems[0] = new Item("Cure_Burn","Cure",1,PossibleItemActions[0]);
  PossibleItems[1] = new Item("Regen_Potion","Status",1,PossibleItemActions[1]);
  PossibleItems[2] = new Item("Heal_Potion","Heal",1,PossibleItemActions[2]);
};

GameSave::~GameSave() {
  // Delete list of prefab Characters
  for (int iChar = 0; iChar < nPossibleCharacters; iChar++) {
    delete PossibleCharacters[iChar];
  }
  delete PossibleCharacters;

  // Delete list of prefab Moves
  for (int iMove = 0; iMove < nPossibleMoves; iMove++) {
    delete PossibleMoves[iMove];
  }
  delete PossibleMoves;

  // Delete list of prefab Items
  for (int iItem = 0; iItem < nPossibleItems; iItem++) {
    delete PossibleItems[iItem];
  }
  delete PossibleItems;
};

Character* GameSave::loadFromFile(string filename) {
  // Open Save file with name provided
  ifstream saveFile;
  saveFile.open(filename + ".txt");
  string characterName;
  // Extract Character name from file
  saveFile >> characterName;
  saveFile.close();
  // Run through list of characters and find which one has that name
  for (int iChar = 0; iChar < nPossibleCharacters; iChar++) {
    if (characterName == PossibleCharacters[iChar]->Name) {
      // Clone and return that character
      return PossibleCharacters[iChar][0].clone();
    }
  }
  // If the character isn't found return a nullpointer.
  return nullptr;
};

bool GameSave::saveToFile(string filename, string characterName) {
  // Open file with name provided
  ofstream saveFile;
  saveFile.open(filename + ".txt");
  // Save characters name into file
  saveFile << characterName;
  // Close file
  saveFile.close();
  return true;
};

Character* GameSave::selectCharacter() {
  cout << "Select a character" << endl;
  cout << "==================" << endl;
  // Loop through all possible characters and display their stats
  for (int iChar = 0; iChar < nPossibleCharacters; iChar++) {
    cout << "Character " << iChar + 1 << endl;
    cout << "Name: " << PossibleCharacters[iChar][0].Name << endl;
    cout << "Health: " << PossibleCharacters[iChar][0].maxHP << endl;
    cout << "Attack: " << PossibleCharacters[iChar][0].baseAtt << endl;
    cout << "Defence: " << PossibleCharacters[iChar][0].baseDef << endl;
    cout << "Speed: " << PossibleCharacters[iChar][0].baseSpeed << endl;
    cout << "Heal: " << PossibleCharacters[iChar][0].baseHeal << endl;
    cout << "==================" << endl;
  }
  // Get a user input
  string selectedCharacter = "";
  bool isValid = false;  // Test if input if valid
  while (!isValid) {     // Keep asking until user provides valid input
    cin >> selectedCharacter;
    // Loop through all possible characters and test if user input is name of
    // the character
    for (int iChar = 0; iChar < nPossibleCharacters; iChar++) {
      if (selectedCharacter == PossibleCharacters[iChar][0].Name) {
        // If the user input matches the prefabe characters name then return a
        // clone of this character
        isValid = true;
        return PossibleCharacters[iChar][0].clone();
      }
    }
    if (!isValid) {  // If user input matched no valid input tell the user to
                     // try again
      cout << "Please enter a valid option" << endl;
    }
  }
};