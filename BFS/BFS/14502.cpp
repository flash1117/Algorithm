#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[8][8];
int copymap[8][8];
bool visited[8][8];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <pair<int, int>> vec;

void print() {


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void copyMap() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			copymap[i][j] = map[i][j];

		}
	}
}

void makeWall(int cnt) {
	int x1, x2, y1, y2;
	if (cnt == 3) {
		copymap[x1][y1] = 0;
		copymap[x2][y2] = 0;
	}
	else {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (map[i][j] == 0) {
					copymap[i][j] = 1;

					if (cnt == 1) {
						x1 = i;
						y1 = j;
					}
					else if (cnt == 2) {
						x2 = i;
						y2 = j;
					}

					makeWall(cnt + 1);
				}

			}

		}
	}
}

void BFS() {

	queue <pair<int, int>> q;


}

int main() {
	int wall = 3;

	memset(map, 0, sizeof(map));
	memset(copymap, 0, sizeof(copymap));
	memset(visited, false, sizeof(visited));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				vec.push_back({ i,j });
		}
			
	}

	copyMap();

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (map[i][j] == 0) {
				copymap[i][j] = 1;
				makeWall(1);
				BFS();
				copymap[i][j] = 0;
			}
		}
	}



	return 0;
}