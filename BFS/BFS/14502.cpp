#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[9][9];
int copy_map[9][9];
int safe = 0, max_safe = 0;
bool safe_state = false;

vector <pair<int, int>> vec;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y, cnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N || y>M) return false;
	return true;
}

void print() {

	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << map[i][j];
		}
		cout << endl;
	}
}


void init() {
	for (int i = 0; i < N; i++) { // init
		for (int j = 0; j < M; j++)
			copy_map[i][j] = map[i][j];
	}

}

bool isFull() {
	safe_state = false;
	safe = 0;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++)
		{
			if (copy_map[i][j] == 0) {
				safe_state= true;
				safe++;
			}
				

		}
	}
	if(safe_state)
		return false;
	return true;
}

void BFS() {

	queue <pos> q;

	for (int i = 0; i < vec.size(); i++)
	{
		q.push({ vec[i].first, vec[i].second, 0 });
	}

	while (!q.empty()) {

//		print();
		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && copy_map[nextX][nextY] == 0)
			{
				q.push({ nextX, nextY, ccnt + 1});
				copy_map[nextX][nextY] = 2;

				
			}

		}
		
	}
	if (isFull()); // 3칸 세웠는데 virus 가 다 펴졌는가
	else {
		if (safe > max_safe)
			max_safe = safe;
	}

	init();
}

void makeWall() {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			for (int k = 0; k < 8; k++) {

				if (isBoundary(i, j) && isBoundary(j, k) && isBoundary(k, i) &&
					map[i][j] == 0 && map[j][k] == 0 && map[k][i] == 0) {
					copy_map[i][j] = 1;
					copy_map[j][k] = 1;
					copy_map[k][i] = 1;

					BFS();
					copy_map[i][j] = 0;
					copy_map[j][k] = 0;
					copy_map[k][i] = 0;
				}
			}
		}
	}


}


int main() {

	memset(map, 0, sizeof(map));
	memset(copy_map, 0, sizeof(copy_map));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> map[i][j];

			if (map[i][j] == 2)
				vec.push_back({ i,j });
		}
	}
	
	init();
	makeWall();
	
	cout << max_safe;

	return 0;
}