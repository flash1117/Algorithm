#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int M, N, H;
int map[101][101][101];
bool visited[101][101][101];

int dx[] = { 0,0,0,0,-1,1 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { -1,1,0,0,0,0 };

typedef struct {

	int z, x, y;
}tomato;

typedef struct {

	int z, x, y, cnt;

}pos;

vector <tomato> vec;

bool isBoundary(int x, int y, int z) {

	if (x<0 || y<0 || z<0 || x>N - 1 || y>M - 1 || z>H - 1) return false;
	return true;

}

int BFS() {
	
	int day = 0;
	queue <pos> q;

	for (int i = 0; i < vec.size(); i++) {
		q.push({ vec[i].z, vec[i].x, vec[i].y , 0 });
		visited[vec[i].z][vec[i].x][vec[i].y] = true;
	}
		
	while (!q.empty()) {
		
		int curH = q.front().z;
		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		if (ccnt > day) day = ccnt;

		for (int i = 0; i < 6; i++) {
			int nextH = curH + dz[i];
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY, nextH) && map[nextH][nextX][nextY] == 0
				&& !visited[nextH][nextX][nextY]) {

				visited[nextH][nextX][nextY] = true;
				map[nextH][nextX][nextY] = 1;
				q.push({ nextH, nextX, nextY, ccnt + 1 });
			}

		}

	}

	for (int i = 0; i < H; i++) 
		for (int j = 0; j < N; j++) 
			for (int k = 0; k < M; k++) 
				if (!visited[i][j][k])
					return -1;
			
	return day;
}

int tomatoCheck() {

	for (int k = 0; k < H; k++) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				if (map[k][i][j] == 0) return 0;
			}
		}
	}
	return -1;
}

void print() {

	cout << endl;
	for (int k = 0; k < H; k++) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				cout << map[k][i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main() {

	memset(visited, false, sizeof(visited));
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				cin >> map[k][i][j];
				if (map[k][i][j] == 1)
					vec.push_back({ k,i,j });
				else if (map[k][i][j] == -1)
					visited[k][i][j] = true;
			}

		}
	}
	
	int check = tomatoCheck();
	if (check == -1) {
		cout << "0";
	}
	else {
		int ret = BFS();
		if (ret == -1)
			cout << "-1";
		else
			cout << ret;
	}

//	print();
	return 0;
}