#include <iostream>

using namespace std;

char play[] = { 'E', 'A', 'B', 'C', 'D', 'E' };

int main() {

	int input;
	for (int i = 0; i < 3; i++) {
		int bot = 0;
		for (int i = 0; i < 4; i++) {
			cin >> input;
			if (input == 0) bot++;
			
		}

		cout << play[bot] << "\n";

	}



	return 0;
}