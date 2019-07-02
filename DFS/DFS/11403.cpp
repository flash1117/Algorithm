#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];

bool isBoundary(int x, int y) {

	if (x <0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void DFS(int start,int now) {
	if (visited[start][now]) return;
	visited[start][now] = 1;
	for (int i = 0; i < N; i++) {
		if (map[now][i]) DFS(start, i);
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
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j]) DFS(i, j);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}