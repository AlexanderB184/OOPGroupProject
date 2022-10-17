#include "UI.h"

#include <iostream>
#include <string>

using namespace std;

UI::UI() {}

UI::~UI() {}

void UI::selectCharacter(Controller *Player) {
  cout << "Select a Character" << endl;
  cout << "==================" << endl;
  int nChar = 4;
  Character **possibleCharacters = new Character *[nChar];
  Move **Moves1 = new Move *[3];
  Moves1[0] = new Attack_Move("Stab", 1000, 25, 80);
  Moves1[1] = new Attack_Move("Shoot", 1, 100, 20);
  Moves1[2] = new Heal_Move("Meditate", 6, 30);
  possibleCharacters[0] = new Character("Bob", 50, 75, 40, 100, 20, Moves1, 3);
  Move **Moves2 = new Move *[3];
  Moves2[0] = new Attack_Move("Stab", 1000, 30, 80);
  Moves2[1] = new Attack_Move("Tackle", 1000, 20, 100);
  Moves2[2] = new Heal_Move("Eat", 10, 30);
  possibleCharacters[1] =
      new Character("Jane", 200, 45, 100, 20, 40, Moves2, 3);
  Move **Moves3 = new Move *[3];
  Moves3[0] = new Attack_Move("Stab", 1000, 30, 80);
  Moves3[1] = new Heal_Move("t", 1000, 20);
  Moves3[2] = new Heal_Move("T", 1, 100);
  possibleCharacters[2] = new Character("T", 100, 25, 70, 60, 100, Moves3, 3);
  Move **Moves4 = new Move *[3];
  Moves4[0] = new Attack_Move("Yell", 100, 1, 000);
  Moves4[1] = new Attack_Move("Stab", 1000, 30, 80);
  Moves4[2] = new Heal_Move("Eat", 10, 30);
  possibleCharacters[3] = new Character("Mark", 100, 50, 50, 50, 50, Moves4, 3);
  for (int iChar = 0; iChar < nChar; iChar++) {
    Character *Char = possibleCharacters[iChar];
    cout << "Character" << iChar + 1 << ": " << endl;
    cout << "Name: " << (*Char).Name << endl;       // Name
    cout << "Health: " << (*Char).maxHP << endl;    // HP
    cout << "Att:" << (*Char).baseAtt << endl;      // Attack
    cout << "Def:" << (*Char).baseDef << endl;      // Defence
    cout << "Speed:" << (*Char).baseSpeed << endl;  // Speed
    cout << "Heal: " << (*Char).baseHeal << endl;   // Heal
    cout << "Moves: " << endl;
    for (int iMove = 0; iMove < (*Char).numberOfMoves; iMove++) {
      Move *cMove = (*Char).Moveset[iMove];
      cout << "Move " << iMove + 1 << ": " << (*cMove).name << endl;
      cout << (*cMove).description << endl;
    }
    cout << "==================" << endl;
  }
  bool isValid = false;
  Character *selected;
  int selectedIndex;
  string selectedCharacter = "";
  while (!isValid) {
    cin >> selectedCharacter;
    for (int iChar = 0; iChar < nChar; iChar++) {
      if (possibleCharacters[iChar][0].Name ==
          selectedCharacter) {  // || iChar + 1 == to_string(selectedCharacter))
                                // {
        isValid = true;
        selected = possibleCharacters[iChar];
        selectedIndex = iChar;
      }
    }
    if (!isValid) {
      cout << "Please select a valid option" << endl;
    }
  }
  cout << "Delete Others" << endl;
  for (int iChar = 0; iChar < nChar; iChar++) {
    if (iChar != selectedIndex) {
      cout << "Deleting " << iChar + 1 << "th Character" << endl;
      delete possibleCharacters[iChar];
    }
  }
  cout << "Deleting Array of Pointers" << endl;
  delete possibleCharacters;
  cout << "Successfully Deleted all pointers" << endl;
  cout << Player << endl;
  Player[0].character = selected;
}