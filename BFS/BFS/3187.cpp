#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char map[251][251];
bool visited[251][251];
int R, C;
int sheep, wolf;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y;
}pos;

void print() {
	cout << endl;
	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {

			cout << visited[i][j];
		}
		cout << endl;
	}

}

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>R - 1 || y>C - 1) return false;
	return true;
}

void BFS(int x, int y) {

	int lw =0 , ls =0;
	queue <pos> q;
	visited[x][y] = true;
	
	q.push({ x,y });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;

		q.pop();

		if (map[curX][curY] == 'v') 
			lw++;
		
		else if (map[curX][curY] == 'k') 
			ls++;
		
		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] != '#' && !visited[nextX][nextY]) {

				q.push({ nextX, nextY});
				visited[nextX][nextY] = true;
			}

		}

	}

	if (ls > lw) 
		sheep += ls;
	
	else 
		wolf += lw;
	
		
}

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

		}
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && map[i][j] != '#') {
				BFS(i, j);
			
			}			
		}
	}
	cout << sheep << " " << wolf;

	return 0;
}