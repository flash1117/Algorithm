#include <iostream>

using namespace std;

int book[10];
int main() {

	int sum;
	cin >> sum;

	for (int i = 0; i < 9; i++) {
		cin >> book[i];
		sum -= book[i];
	}
	cout << sum;
	return 0;
}