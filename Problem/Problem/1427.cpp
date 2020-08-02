#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	char arr[11] = "";
	string input;
	cin >> input;
	const int LEN = input.length();
	for (int i = 0; i < input.length(); i++) {
		arr[i] = input[i];
	}

	sort(arr, arr + LEN, greater<>());

	cout << arr << "\n";

	return 0;
}