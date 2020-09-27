#include <iostream>

using namespace std;

int n;
int map[128][128];
int blue, white;

bool isSame(int startX, int startY, int endX, int endY) {

	int prev = map[startX][startY];

	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {

			if (startX == i && startY == j) continue;
			else if (map[i][j] != prev) return false;
			
			prev = map[i][j];
		}
	}

	return true;
}


void solve(int startX, int startY, int endX, int endY) {

	if (startX == endX) {

		if (map[startX][startY]) blue++;
		else white++;

		return;
	}

	bool sameCheck = isSame(startX, startY, endX, endY);
	if (sameCheck) {

		if (map[startX][startY]) blue++;
		else white++;
		return;
	}
	else {

		int midX = (startX + endX) / 2;
		int midY = (startY + endY) / 2;

		solve(startX, startY, midX, midY);
		solve(midX+1, startY, endX, midY);
		solve(startX, midY+1, midX, endY);
		solve(midX + 1, midY + 1, endX, endY);

	}

	return;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	solve(0, 0, n - 1, n - 1);
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}