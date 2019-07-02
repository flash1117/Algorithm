#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[8][8];
bool visited[8][8];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <pair<int, int>> virus;
vector <int> ret;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isBoundary(int x, int y) {
	if (x < 0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void BFS() {
	//print();
	queue <pair<int, int>> q;
	int cnt = 0;
	
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
		visited[virus[i].first][virus[i].second] = true;
	}
	
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && !visited[nextX][nextY]) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
				cnt++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	ret.push_back(cnt);
}

void MakeWall(int n, int cnt) {
	if (n >= N*M|| map[n / M][n % M]) return;
	map[n / M][n % M] = 1;
	if (cnt == 3) {
		BFS();
		//print();
	} else{
		for (int i = n+1; i < N*M; i++) {
			MakeWall(i, cnt + 1);
		}
	}
	map[n / M][n % M] = 0;
}

int main() {
	cin >> N >> M;
	int maxSafe = 0;
	int safeZone = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });
			else if (map[i][j] == 0)
				safeZone++;
		}
			
	for (int i = 0; i < N*M; i++) {
		MakeWall(i, 1);
	}

	for (int i = 0; i < ret.size(); i++) 
		if (safeZone - ret[i] > maxSafe) maxSafe = safeZone - ret[i];
	
	cout << maxSafe-3;
	return 0;
}