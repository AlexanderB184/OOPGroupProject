#include "GameSave.h"
#include "Attack_Move.h"
#include "Heal_Move.h"

GameSave::GameSave() {
    nPossibleMoves = 4;
    PossibleMoves = new Move*[nPossibleMoves];
    PossibleMoves[0] = new Attack_Move("Stab", 1000, 35, 75);
    PossibleMoves[1] = new Attack_Move("Slash", 1000, 20, 90);
    PossibleMoves[2] = new Attack_Move("Shoot", 6, 65, 50);
    PossibleMoves[3] = new Heal_Move("Meditate", 5, 50, 2);
    nPossibleCharacters = 4;
    PossibleCharacters = new Character*[nPossibleCharacters];
    int Moves1[3] = {0, 1, 3};
    PossibleCharacters[0] = new Character("Bob", 50, 75, 40, 100, 20, PossibleMoves, Moves1, 3);
    int Moves2[3] = {1, 2, 3};
    PossibleCharacters[1] = new Character("Jane", 200, 40, 75, 30, 50, PossibleMoves, Moves2, 3);
    int Moves3[3] = {1, 2, 3};
    PossibleCharacters[2] = new Character("T", 50, 75, 40, 100, 20, PossibleMoves, Moves3, 3);
    int Moves4[3] = {0, 2, 3};
    PossibleCharacters[3] = new Character("Mark", 100, 50, 50, 50, 50, PossibleMoves, Moves4, 3);
    cout << PossibleCharacters[2][0].Moveset[0][0].name << endl;

    Character1 = nullptr;
    Character2 = nullptr;
    Players = new Controller*[2];
    Players[0] = new HumanController(nullptr, nullptr, 0);
    Players[1] = new ComputerController(nullptr, nullptr, 0);
    OngoingBattle = Battle(Players, 0);

  
};

GameSave::~GameSave() {
  delete Players[0];
  delete Players[1];
  delete Players;
  delete Character1;
  delete Character2;

};

bool GameSave::loadFromFile(string filename) { 
    string data;
    string name = "Bob";
    string name2 = "Jane";
    Character1 = new Character(name);
    Character2 = new Character(name2);
    //Items
};

bool GameSave::saveToFile(string filename){
    //Write names to file
};

Character* GameSave::selectCharacter() {
    cout << "Select a character" << endl;
    cout << "==================" << endl;
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
  string option = "new";
  bool isValid = false;
  while (!isValid) {
    cin >> option;
    for (int iChar = 0; iChar < nPossibleCharacters; iChar++) {
        if (option == PossibleCharacters[iChar][0].Name) {
            isValid = true;
            return PossibleCharacters[iChar][0].clone();
        }
    }
    if (!isValid) {
      cout << "Please enter a valid option" << endl;
    }
    }

};