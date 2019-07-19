#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char map[251][251];
bool visited[251][251];
int R, C, sheep =0, wolf=0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {

	if (x< 0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {
			cout << visited[i][j] << " ";

		}
		cout << endl;
	}

}
void BFS(int x, int y) {

	queue <pair<int, int>> q;
	int scnt = 0, wcnt = 0;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (map[curX][curY] == 'o')
			scnt++;
		else if (map[curX][curY] == 'v')
			wcnt++;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] != '#') {

				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
				
			}

		}

	}

	if (scnt > wcnt)
		sheep += scnt;
	else
		wolf += wcnt;
}

int main() {

	memset(visited, false, sizeof(visited));

	cin >> R >> C;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			cin >> map[i][j];
		
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && !visited[i][j])
				BFS(i,j);
		}
	}

//	print();
	cout << sheep << " " << wolf;
	return 0;
}