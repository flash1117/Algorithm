#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[101][101];
int matrix[101][101];


void BFS(int point) {

	queue <int> q;

	for (int i = 0; i < N; i++) {

		if (map[point][i]) {
			q.push(i);
			matrix[point][i] = 1;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (map[cur][i]&&!matrix[point][i]) {
				q.push(i);
				matrix[point][i] = 1;
			}

		}
	}
}

void print() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cout << matrix[i][j]<<" ";
			
		}
		cout << endl;
	}

}

int main() {

	memset(map, 0, sizeof(map));
	memset(matrix, 0, sizeof(matrix));

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
		}

	}

	for (int i = 0; i < N; i++)
		BFS(i);
	print();

	return 0;
}