#include <iostream>
#include <vector>

using namespace std;

int n;
int map[20][20];
bool visited[20][20];

int solve() {

	int sum = 0;
	for (int k = 0; k < n; k++) {

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++)
			{
				if (map[i][j] != 0 && map[i][k] != 0 && map[k][j] != 0
					&& map[i][j] == map[i][k] + map[k][j]) {
					
					visited[i][j] = true;
				}
				else if (map[i][j] > map[i][k] + map[k][j]) return -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && j>i) sum += map[i][j];
		}
	}

	return sum;
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cin >> map[i][j];
		}
	}
	cout << solve()<< "\n";

	return 0;
}