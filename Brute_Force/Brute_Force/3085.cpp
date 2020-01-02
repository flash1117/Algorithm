#include <iostream>
#include <queue>

using namespace std;
int N;
char map[50][50];

int getMaxLen(int x, int y) {

	int ret = 0;
	int cnt = 1;
	for (int i = 0; i < N-1; i++) {

		if (map[i][y] == map[i + 1][y]) cnt++;
		else break;
	}
	ret = ret > cnt ? ret : cnt;
	cnt = 1;

	for (int i = 0; i < N - 1; i++) {

		if (map[i][y+1] == map[i + 1][y+1]) cnt++;
		else break;
	}
	ret = ret > cnt ? ret : cnt;
	cnt = 1;

	for (int i = 0; i < N-1; i++) {
		if (map[x][i] == map[x][i + 1]) cnt++;
		else break;
	}
	ret = ret > cnt ? ret : cnt;
	cnt = 1;

	for (int i = 0; i < N - 1; i++) {
		if (map[x + 1][i] == map[x + 1][i + 1]) cnt++;
		else break;
	}
	ret = ret > cnt ? ret : cnt;
	return ret;
}

void swap(int i, int j, int mode) {

	if (mode == 0) {
		char temp = map[i][j];
		map[i][j] = map[i][j + 1];
		map[i][j + 1] = temp;
	}
	else {
		char temp = map[i][j];
		map[i][j] = map[i + 1][j];
		map[i + 1][j] = temp;

	}
}

int main() {

	ios_base::sync_with_stdio(false);

	int maxLen = 0;
	string input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			map[i][j] = input[j];
		}
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {

				swap(i, j, 0);

				int ret = getMaxLen(i,j);
				maxLen = ret > maxLen ? ret : maxLen;

				swap(i, j, 0);
			}
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {

			if (map[i][j] != map[i + 1][j]) {

				swap(i, j, 1);
				int ret = getMaxLen(i,j);
				maxLen = ret > maxLen ? ret : maxLen;

				swap(i, j, 1);
			}
		}
	}
	
	cout << maxLen << "\n";
	return 0;
}