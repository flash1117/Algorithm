#include <iostream> 

using namespace std;

int main()
{
	int input = 0;

	cin >> input;

	if (input >= 90) cout << "A" << "\n";
	else if (input < 90 && input >= 80) cout << "B" << "\n";
	else if (input < 80 && input >= 70) cout << "C" << "\n";
	else if (input < 70 && input >= 60) cout << "D" << "\n";
	else cout << "F" << "\n";

	return 0;
}