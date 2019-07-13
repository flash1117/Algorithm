#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef struct {

	int x, y;

}pos;

int M, N;
int map[101][101];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

pos src, dst, dir;

void BFS() {




}

int main() {

	cin >> M >> N;
	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

		}
	}

	cin >> src.x >> src.y >> dir.x;
	cin >> dst.x >> dst.y >> dir.y;

	BFS();

	return 0;
}