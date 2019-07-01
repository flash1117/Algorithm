#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[8][8];
bool visited[8][8];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


void print() {


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int wall = 3;

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		for(int j=0; j<M; j++)
			cin >> map[i][j];
	}

	for (int f = 0; f < N; f++) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {


			}
		}
	}

	return 0;
}