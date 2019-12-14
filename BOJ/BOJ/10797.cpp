#include <iostream>

using namespace std;

int main() {
	int day, input;
	int cnt = 0;
	cin >> day;
	for (int i = 0; i < 5; i++)
	{
		cin >> input;
		if (input == day) cnt++;
	}
	cout << cnt;
	return 0;
}