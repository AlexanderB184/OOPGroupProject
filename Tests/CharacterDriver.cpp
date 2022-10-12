#include "Status.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main(void) {
  srand(time(NULL));
  // test 1
  {
    try {
      Character Test1 = Character();
    }
    catch (...) { 
        cout << "Test 1 Failed" << endl; 
    }
  }
  // test 2
  { 
    Character Test2 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0); 
    if (Test2.Name != "Isaac" || Test2.HP != 100 ) {
    cout << "Test 2 Failed" << endl; 
    }
  }
  // test 3
  { 
    try {
    Character Test3 = Character("", 0, 0, 0, 0, 0, nullptr, 0); 
    }
    catch (...) { 
        cout << "Test 3 Failed" << endl; 
    }
  }

  // test 4
  // need to add statuses first

  {
    Character Test4 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test4.ApplyStatus();
  }

  //test 5
  {
    Character Test5 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Status** Effects = new Status*[1];
    Effects[0] = new BurnEffect(5, 10);
    Test5.StatusEffect = Effects;
    Test5.numberOfEffects = 1;
    Test5.ApplyStatus();
    if (Test5.HP != 95) {
      cout << "Test 5 Failed Invalid HP " << Test5.HP << endl;
    }
    if (Test5.dead) {
      cout << "Test 5 Failed Character Died" << endl;
    }
    if (Test5.StatusEffect[0][0].duration != 9) {
      cout << "Test 5 Failed Invalid Duration " << Test5.StatusEffect[0][0].duration << endl;
    }
  }
  //test 6
  {
    Character Test6 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test6.HP = 5;
    Status** Effects = new Status*[1];
    Effects[0] = new BurnEffect(5, 10);
    Test6.StatusEffect = Effects;
    Test6.numberOfEffects = 1;
    Test6.ApplyStatus();

    if (Test6.HP != 0) {
      cout << "Test 6 Failed Invalid HP " << Test6.HP << endl;
    }
    if (!Test6.dead) {
      cout << "Test 6 Failed Character Did Not Die" << endl;
    }
    if (Test6.StatusEffect[0][0].duration != 9) {
      cout << "Test 6 Failed Invalid Duration " << Test6.StatusEffect[0][0].duration << endl;
    }
  }
  //test 7
  {
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 1;
    Status** Effects = new Status*[1];
    Effects[0] = new BurnEffect(5, 10);
    Test7.StatusEffect = Effects;
    Test7.numberOfEffects = 1;
    Test7.ApplyStatus();

    if (Test7.HP != 0) {
      cout << "Test 7 Failed Invalid HP " << Test7.HP << endl;
    }
    if (!Test7.dead) {
      cout << "Test 7 Failed Character Did Not Die" << endl;
    }
    if (Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 7 Failed Invalid Duration " << Test7.StatusEffect[0][0].duration << endl;
    }
  }

  //test 8
  {
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 100;
    Status** Effects = new Status*[1];
    Effects[0] = new RegenEffect(5, 10);
    Test7.StatusEffect = Effects;
    Test7.numberOfEffects = 1;
    Test7.ApplyStatus();
    if (Test7.HP != 100 || Test7.dead || Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 8 Failed" << endl;
    }
  }
   //test 9
  {
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 35;
    Status** Effects = new Status*[1];
    Effects[0] = new RegenEffect(5, 10);
    Test7.StatusEffect = Effects;
    Test7.numberOfEffects = 1;
    Test7.ApplyStatus();
    if (Test7.HP != 40 || Test7.dead || Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 9 Failed" << endl;
    }
  }
  //test 10
  {
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Status** Effects = new Status*[1];
    Effects[0] = new StunEffect(0, 10);
    Test7.StatusEffect = Effects;
    Test7.numberOfEffects = 1;
    Test7.ApplyStatus();
    if (Test7.missNextTurn == true) {
      cout << "Test 10 Failed" << endl;
    }
  }
  
  //Test 11
  {
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Status** Effects = new Status*[1];
    Effects[0] = new StunEffect(100, 10);
    Test7.StatusEffect = Effects;
    Test7.numberOfEffects = 1;
    Test7.ApplyStatus();
    if (Test7.missNextTurn == false) {
      cout << "Test 11 Failed" << endl;
    }
  }

  //Test 12
  {
  int S = 0;
  Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
  Status** Effects = new Status*[1];
  Effects[0] = new StunEffect(50, 1000);
  Test7.numberOfEffects = 1;
  Test7.StatusEffect = Effects;
  for (int i = 0; i < 100; i++) {
    Test7.missNextTurn = false;
    Test7.ApplyStatus();
    if (Test7.missNextTurn) {
      S++;
    }
    }
  cout << "Test 12: " << S << endl;
  }
  

//Test 13
{
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Status** Effects = new Status*[2];
    Effects[0] = new BurnEffect(5, 10);
    Effects[1] = new RegenEffect(5, 10);
    Test7.numberOfEffects = 2;
    Test7.StatusEffect = Effects;
    Test7.ApplyStatus();
    if (Test7.HP != 100 || Test7.dead || Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 13 Failed" << endl;
    }
  }
//Test 14
{
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 5;
    Status** Effects = new Status*[2];
    Effects[0] = new BurnEffect(5, 10);
    Effects[1] = new RegenEffect(5, 10);
    Test7.numberOfEffects = 2;
    Test7.StatusEffect = Effects;
    Test7.ApplyStatus();
    if (Test7.HP != 5) {
      cout << "Test 14 Failed Invalid HP " << Test7.HP << endl;
    }
    if (Test7.dead) {
      cout << "Test 14 Failed Character Died" << endl;
    }
    if (Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 14 Failed Invalid Duration " << Test7.StatusEffect[0][0].duration << endl;
    }
    if (Test7.StatusEffect[1][0].duration != 9) {
      cout << "Test 14 Failed Invalid Duration " << Test7.StatusEffect[1][0].duration << endl;
    }
  }
//Test 15
{
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 1;
    Status** Effects = new Status*[2];
    Effects[0] = new BurnEffect(5, 10);
    Effects[1] = new RegenEffect(5, 10);
    Test7.numberOfEffects = 2;
    Test7.StatusEffect = Effects;
    Test7.ApplyStatus();
    if (Test7.HP != 1) {
      cout << "Test 15 Failed Invalid HP " << Test7.HP << endl;
    }
    if (Test7.dead) {
      cout << "Test 15 Failed Character Died" << endl;
    }
    if (Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 15 Failed Invalid Duration " << Test7.StatusEffect[0][0].duration << endl;
    }
    if (Test7.StatusEffect[1][0].duration != 9) {
      cout << "Test 15 Failed Invalid Duration " << Test7.StatusEffect[1][0].duration << endl;
    }
  }
//Test 16
{
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 35;
    Status** Effects = new Status*[2];
    Effects[0] = new BurnEffect(5, 10);
    Effects[1] = new RegenEffect(5, 10);
    Test7.numberOfEffects = 2;
    Test7.StatusEffect = Effects;
    Test7.ApplyStatus();
    if (Test7.HP != 35 || Test7.dead ||Test7.StatusEffect[1][0].duration != 9|| Test7.StatusEffect[0][0].duration != 9) {
      cout << "Test 16 Failed" << endl;
    }
  }
//Test 17
{
    Character Test7 = Character("Isaac", 100, 50, 50, 50, 50, nullptr, 0);
    Test7.HP = 50;
    Status** Effects = new Status*[3];
    Effects[0] = new BurnEffect(5, 10);
    Effects[1] = new RegenEffect(5, 10);
    Effects[2] = new StunEffect(50, 10);
    Test7.numberOfEffects = 3;
    Test7.StatusEffect = Effects;
    Test7.ApplyStatus();
    if (Test7.HP != 50 || Test7.dead || Test7.StatusEffect[0][0].duration != 9||Test7.StatusEffect[1][0].duration != 9|| Test7.StatusEffect[2][0].duration != 9) {
      cout << "Test 17 Failed" << endl;
    }
  }
return 0;
}
