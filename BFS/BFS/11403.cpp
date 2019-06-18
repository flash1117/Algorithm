#include <iostream>
#include <queue>

using namespace std;

int N;
int map[101][101];
int matrix[101][101];

bool valueCheck() {

	if (N > 100 || N < 1) return false;
	return true;
}

void print() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

int BFS() {


}

int main() {

	cin >> N;
	memset(map, 0, sizeof(map));
	memset(matrix, 0, sizeof(matrix));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
		}

	}
	print();

	return 0;
}