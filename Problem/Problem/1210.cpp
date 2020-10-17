#include <iostream>

using namespace std;

int map[100][100], arriveIndex;
pair<int, int> start;
bool visited[100][100];

void init() {

	for (int i = 0; i < 100; i++) {

		for (int j = 0; j < 100; j++) {

			visited[i][j] = false;
		}
	}

	arriveIndex = 0;

	return;
}


bool isBoundary(int x, int y) {

	if (x < 0 || y < 0 || x>99 || y>99) return false;
	return true;
}

void solve(int x, int y) {

	if (x == 0)
	{
		arriveIndex = y;
		return;
	}

	bool state = false;
	if (isBoundary(x, y + 1) && map[x][y + 1] == 1 && !visited[x][y+1]) {
		state = true;
		visited[x][y + 1] = true;
		solve(x, y + 1);
		visited[x][y + 1] = false;
	}

	if (isBoundary(x, y - 1) && map[x][y - 1] == 1 && !visited[x][y-1]) {
		state = true;
		visited[x][y - 1] = true;
		solve(x, y - 1);
		visited[x][y - 1] = false;
	}

	if (!state && isBoundary(x-1, y) && map[x-1][y] == 1 && !visited[x-1][y]) {
		visited[x-1][y] = true;
		solve(x - 1, y);
		visited[x - 1][y] = false;
	}

	return;

}


int main() {

	int t = 10;
	while (t--) {

		int num;
		cin >> num;

		init();

		for (int i = 0; i < 100; i++) {

			for (int j = 0; j < 100; j++) {

				cin >> map[i][j];
				if (map[i][j] == 2) {
					start.first = i;
					start.second = j;
				}
			}
		}

		solve(start.first, start.second);

		cout << "#" << num << " " << arriveIndex << "\n";
	}

	return 0;
}