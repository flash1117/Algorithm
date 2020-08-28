#include <iostream>

using namespace std;

int n, answer = 987654321;
int map[10][10];
bool visited[10];


bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return false;
	return true;
}

bool isAllVisit() {

	for (int i = 0; i < n; i++) {
		if (!visited[i]) return false;
	}
	return true;
}
void travel(int index, int cost) {

	if (index == 0 && cost > 0 && isAllVisit()) {
		answer = answer > cost ? cost : answer;
		return;
	}


	for (int i = 0; i < n; i++) {

		if (visited[i]) continue;
		else if (map[index][i] != 0) {
			visited[i] = true;
			travel(i, cost + map[index][i]);
			visited[i] = false;
		}

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

	travel(0, 0);
	cout << answer << "\n";
	return 0;
}