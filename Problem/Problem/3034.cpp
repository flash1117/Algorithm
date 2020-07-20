#include <iostream>

using namespace std;

bool isContain(int size, int w, int h) 
{
	int sum = w * w + h * h;

	if (sum >= size * size) 
		return true;

	return false;
}

int main() {


	int n, w, h;
	cin >> n >> w >> h;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (isContain(input, w, h)) cout << "DA\n";
		else cout << "NE\n";

	}


	return 0;
}