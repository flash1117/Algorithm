#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {

		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		cout << temp.first + temp.second << "\n";

	}

	return 0;
}