#include "GameSave.h"

GameSave::GameSave() {
  Character1 = Character();
  Character2 = Character();
  Players = new Controller*[2];
  Players[0] = new HumanController(&Character1, nullptr, 0);
  Players[1] = new ComputerController(&Character2, nullptr, 0);
  OngoingBattle = Battle(Players, 0);
};

GameSave::~GameSave() {
  delete Players[0];
  delete Players[1];
  delete Players;
};

bool GameSave::loadFromFile(string filename) { 
    string data;
    string name = "Bob";
    string name2 = "Jane";
    Character1 = Character(name);
    Character2 = Character(name2);
    //Items
};

bool GameSave::saveToFile(string filename){
    //Write names to file
};