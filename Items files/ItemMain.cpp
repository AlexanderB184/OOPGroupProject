#include <iostream>
#include "Item.h"

using namespace std;

// Main Item Program for testing
int main(){
	Item *one;
	one = new Item("HealyBoi", "Heal", 1);

	// Testing useItem function
	bool a = true;

	while (a == true){
		if ((one->) <= 0){
			delete one;
			a = false;
		} else{
			one->UseItem();
		}
	}
	cout << endl;

	return 0;
}