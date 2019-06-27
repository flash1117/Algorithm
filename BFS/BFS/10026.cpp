#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int area = 1, blind =0;
bool colorBlind = false;
char map[101][101];
bool visited[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y;
}pos;

bool isBoundary(int x, int y) {

	if (x < 0 || y<0 || x>N || y>N) return false;
	return true;
}

bool isFull() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
				return false;

		}
	}
	return true;
}

void BFS() {

		queue <pos> q;
		q.push({ 0,0 });
		visited[0][0] = 1;

		while (!q.empty()) {

			int curX = q.front().x;
			int curY = q.front().y;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];

				if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[curX][curY] == map[nextX][nextY]) {
					q.push({ nextX,nextY });
					visited[nextX][nextY] = true;

				}
				if ((map[curX][curY] == 'R' && map[nextX][nextY] == 'G') ||
					(map[curX][curY] == 'G' && map[nextX][nextY] == 'R')) {
					colorBlind = true;
					blind++;
				}
					

			}

			if (q.empty()) {
				if (isFull());
				else {
					for (int i = 0; i < N; i++) {
						bool state = false;
						for (int j = 0; j < N; j++) {
							if (!visited[i][j] && !state) {
								q.push({ i,j });
								state = true;
								break;
							}
						}
						if (state)
							break;
					}
					area++;
				}
			}
		}

}

int main() {

	string input;
	cin >> N;

	memset(map, '0', sizeof(map));
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < N; i++) {

		cin >> input;
		for (int j = 0; j < input.length(); j++)
			map[i][j] = input[j];

	}
	
	BFS();

	if (colorBlind)
		cout << area << " " << area - blind;
	else
		cout << area << " " << area;

	return 0;
}