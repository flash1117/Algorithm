#include <iostream>

using namespace std;

int map[101][101];

int main() {
	
	pair<int, int> input;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> input.first >> input.second;
		for (int i = input.first; i < input.first + 10; i++) {
			for (int j = 100 - input.second; j > 90 - input.second; j--) {
				map[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {

			if (map[i][j]) cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}