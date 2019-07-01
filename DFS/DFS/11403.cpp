#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int map[101][101];
bool visited[101];

bool isBoundary(int x, int y) {

	if (x <0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}


void DFS(int relp, int pt) {

	for (int i = 0; i < N; i++) {

		if (map[pt][i] == 1 && !visited[pt]) {
			visited[pt] = true;
			map[relp][pt] = 1;
			DFS(relp, i);

		}
	}

}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	cin >> N;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
		}
	}




	return 0;
}