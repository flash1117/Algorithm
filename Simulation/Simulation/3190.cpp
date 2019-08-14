#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int N, K, L;
int map[101][101];

vector <pair<int, int>> apple;
vector <pair<int, char>> snake;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 }; 

typedef struct {

	int x, y, cnt, dir;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cout << map[i][j] << " ";

		}
		cout << endl;
	}

}

int solve() {

	for (int i = 0; i < apple.size(); i++) 
		map[apple[i].first-1][apple[i].second-1] = 1;
	
	deque <pair<int, int>> tail;
	queue <pos> q;

	q.push({ 0,0,0,0 });
	tail.push_back({ 0,0 });
	map[0][0] = 2;
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		int direct = q.front().dir;

		q.pop();

		int nextX = curX + dx[direct];
		int nextY = curY + dy[direct];

		for (int i = 0; i < snake.size(); i++) {
			if (ccnt == snake[i].first) {

				if (snake[i].second == 'L') {

					if (direct == 0) {
						direct = 3;
						nextX = curX + dx[3];
						nextY = curY + dy[3];
					}

					else {
						nextX = curX + dx[direct - 1];
						nextY = curY + dy[direct - 1];
						direct--;
					}

				}
				else if (snake[i].second == 'D') {
					if (direct == 3)
					{
						direct = 0;
						nextX = curX + dx[0];
						nextY = curY + dy[0];
					}
					else {
						nextX = curX + dx[direct + 1];
						nextY = curY + dy[direct + 1];
						direct++;
					}
				}
			}
		}
		if (isBoundary(nextX, nextY)) {
			q.push({ nextX, nextY, ccnt + 1, direct });
			tail.push_back({ nextX, nextY });

			if (map[nextX][nextY] == 2) {
				map[tail.front().first][tail.front().second] = 0;
				tail.pop_front();
				
				if (tail.front().first == nextX && tail.front().second == nextY);
				else
					return ccnt + 1;
			}
				
			if (map[nextX][nextY] == 0) {
				map[tail.front().first][tail.front().second] = 0;
				tail.pop_front();

			}
			map[nextX][nextY] = 2;
	
		}
		else return ccnt + 1;
	}
}


int main() {

	int input1, input2;
	char dir;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> input1 >> input2;
		apple.push_back(make_pair(input1, input2));
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> input1 >> dir;
		snake.push_back(make_pair(input1, dir));

	}

	int ret = solve();
	cout << ret;
	return 0;
}