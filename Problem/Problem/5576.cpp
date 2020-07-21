#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> w;
vector <int> k;

int main() {
	int input;
	for (int i = 0; i < 10; i++) {
		cin >> input;
		w.push_back(input);

	}
	for (int j = 0; j < 10; j++) {
		cin >> input;
		k.push_back(input);

	}

	sort(w.begin(), w.end(), greater<> ());
	sort(k.begin(), k.end(), greater<>());

	cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << "\n";

	return 0;
}