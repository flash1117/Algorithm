#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char map[1001][1001];
bool visited[1001][1001];
int R, C;
int sx, sy;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <pair<int, int>> fire;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;

}

void print() {

	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}

}

int DFS(int x, int y , int cnt) {

	if (!isBoundary(x, y) && cnt != 0) return cnt;
	if (visited[x][y] || (map[x][y] != '.' && cnt != 0)) return 0;
	
	visited[x][y] = true;
	cout << x << " , " << y << endl;
	queue <pair<int, int>> q;
	for (int i = 0; i < fire.size(); i++) {
		q.push(make_pair(fire[i].first, fire[i].second));
	}
		
	fire.clear();
	for (int i = 0; i < q.size(); i++) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++) {
			int nextX = curX + dx[j];
			int nextY = curY + dy[j];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == '.') {
				fire.push_back(make_pair(nextX, nextY));
				map[nextX][nextY] = 'F';
			}
		}
	}

	print();
	for (int i = 0; i < 4; i++) { // 왜 한번만 돌지?
		cout << "실행" << endl;
		return DFS(x + dx[i], y + dy[i], cnt + 1);

	}
		
	
	return cnt;
}

int main() {

	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				sx = i;
				sy = j;
			}
			else if (map[i][j] == 'F')
				fire.push_back(make_pair(i, j));
		}
	}

	cout << DFS(sx, sy, 0);

	return 0;
}