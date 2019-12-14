#include <iostream>

using namespace std;

int ham[3];
int soda[2];

int main() {

	int set = -50;
	int temp = 2100;
	for (int i = 0; i < 3; i++) {
		cin >> ham[i];
		temp = temp > ham[i] ? ham[i] : temp;
	}
	set += temp;
	
	for (int i = 0; i < 2; i++) {
		cin >> soda[i];
	}
	set += soda[0] > soda[1] ? soda[1] : soda[0];
	cout << set << "\n";
	return 0;
}