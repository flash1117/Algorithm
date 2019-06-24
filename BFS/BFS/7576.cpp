#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define pos pair<int,int>

using namespace std;

typedef struct {

	int x, y, cnt;

}tomato;

int N, M;
int map[1001][1001];
int visited[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isRipe = false;
vector <pos> vec;
int ret;

bool isBoundary(int x, int y) {

	if (x < 0 || y <0 || x>N-1 || y>M-1) return false;
	return true;
}

void print() {

	cout << endl;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << visited[i][j] << " ";
		}
		cout << endl;
	}

}

int BFS() {

	queue <tomato> q;
	
	if (isRipe == false)
		return 0;

	for (int i = 0; i < vec.size(); i++) {
		q.push({ vec[i].first, vec[i].second,0 });
		visited[vec[i].first][vec[i].second] = 1;
		cout << "vec : " << vec[i].first << vec[i].second << endl;

	}
	

	while (!q.empty()) {


		print();

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && visited[nextX][nextY] == 0 && map[nextX][nextY] == 0)
			{
				q.push({ nextX, nextY, ccnt+1 });
				visited[nextX][nextY] = 1;
				ret = ccnt;
			}

			
		}
		
	}
	
}


bool isFullRipe() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (visited[i][j] == 0)
				return false;

		}
	}
	return true;
}

int main() {
	cin >> M >> N;

	if (M < 2 || N < 2 || M >1000 || N>1000)
		return -1;

	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
			if (isRipe == false && map[i][j] == 0)
				isRipe = true;
			if (map[i][j] == 1)
				vec.push_back({ i,j });
			else if (map[i][j] == -1)
				visited[i][j] = 1;

				
		}

	}

	ret = BFS();

	if (!isFullRipe()) {
		cout << "-1";
		return 0;

	}
	else
		cout << ret;
	return 0;
}