#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char map[12][6];
int puyoCnt = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool visited[12][6];

vector <pair<int, int>> pos;

bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>11 || y>5) return false;
	return true;

}

void BFS(int x, int y) {

	char color = map[x][y];
//	cout << color << " ";
	queue <pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		pos.push_back({ curX, curY });

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == color) {
				puyoCnt++;
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}

		}


	}
	
}

void print() {

	for (int i = 0; i < 12; i++) {

		for (int j = 0; j < 6; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

bool posInit() {

	bool bomb = false;

	if (puyoCnt >= 4) { // 뿌요 터트리기
		bomb = true;
		for (int i = 0; i < pos.size(); i++) {

			map[pos[i].first][pos[i].second] = '.';
		}

	}
	
	for (int i = 0; i < pos.size(); i++)
		pos.pop_back();
	
	return bomb;
}

void remake() {

	for (int i = 0; i < 6; i++) {
		int ptCnt = 0;
		for (int j = 0; j < 12; j++) {
			if (map[j][i] >= 'A') break;
			else {
				ptCnt++;
			}

		}

		for (int j = ptCnt; j < 12; j++) {
			map[j - ptCnt][i] = map[j][i];
			map[j][i] = '.';
		}
	}


}
int main() {
	
	int chain = 1;
	bool breakable = true;

	for (int i = 0; i < 12; i++) {

		for (int j = 0; j < 6; j++) {

			cin >> map[12-i][j];
		}
	}

	while (1) {
		breakable = true;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; i++) {

			for (int j = 0; j < 6; j++) {

				if (!visited[i][j] && map[i][j] >= 'A') {
					puyoCnt = 1;
					BFS(i, j);
					if (posInit()) {
						chain++;
						breakable = false;
					}
				}

			}
		}

		if (breakable)
			break;
		remake();
		print();
	}

	cout << endl << chain;

	return 0;
}