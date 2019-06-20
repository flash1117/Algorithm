#include <iostream>
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
			for (int j = 0; j < N; j++) {

				if (map[i][j])
					q.push(j);
			}

		}
	}

	while (!q.empty()) {
		int curY = q.front();
		q.pop();
		map[point][curY] = 1;

	}
}

void print() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cout << map[i][j];
			
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