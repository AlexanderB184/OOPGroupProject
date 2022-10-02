#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
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
    Character Test2 = Character("Isaac", 100, 50, 50, 50, 50, "Moves"); 
    if (Test2.Name != "Isaac" || Test2.HP != 100 ) {
    cout << "Test 2 Failed" << endl; 
    }
  }
  // test 3
  { 
    try {
    Character Test3 = Character("", 0, 0, 0, 0, 0, "Moves"); 
    }
    catch (...) { 
        cout << "Test 3 Failed" << endl; 
    }
  }

  // test 4
  // need to add statuses first
  
  return 0;
}