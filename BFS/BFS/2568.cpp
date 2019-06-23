#include <iostream>
#include <cstring>
#include <queue> 

using namespace std;

int M, N, K;
int map[101][101];


void print() {

	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {

			cout << map[i][j];
		}
		cout << endl;
	}
}

int main() {

	int lx, ly, rx, ry;
	memset(map, 0, sizeof(map));

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {

		cin >> lx >> ly >> rx >> ry;

		for (int j = lx; j <= rx; j++) {
			for (int k = ly; k <= ry; k++) {

				map[j][k] = 1;
			}
		}
	}

	print();

	return 0;
}