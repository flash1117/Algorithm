#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K, X;
int map[101][101];
vector <pair<int, char>> vec;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

typedef struct {
	int x, y, dir;
}pos;

int setDir(int curDir, char rot) {

	if (rot == 'D') { // ¿À¸¥ÂÊ
		if (curDir != 3) return curDir + 1;
		else return 0;
	}
	else if (rot == 'L') // ¿ÞÂÊ
	{
		if (curDir != 0) return curDir - 1;
		else return 3;
	}
	return -1;
}

bool isBoundary(int x, int y) {

	if (x<0 || y< 0 || x>N - 1 || y>N - 1) return false;
	return true;

}

bool isExist(deque <pos>& dq, int nextX, int nextY) {

	for (int i = 0; i < dq.size(); i++) 
		if (nextX == dq[i].x && nextY == dq[i].y) return true;
	return false;
}

int solve() {

	int time = 0, index = 0;
	deque <pos> snake;
	snake.push_front({ 0,0,0 });

	while (!snake.empty()) {

		time++;
		int Dir = snake.front().dir;
		
		if (index < vec.size() && time-1 == vec[index].first) 
			Dir = setDir(Dir, vec[index++].second);
			
		int nextX = snake.front().x + dx[Dir];
		int nextY = snake.front().y + dy[Dir];

		if (isExist(snake, nextX, nextY) || !isBoundary(nextX, nextY)) return time;

		if (map[nextX][nextY] == 1) 
			map[nextX][nextY] = 0;
		else snake.pop_back();

		snake.push_front({ nextX,nextY,Dir });

	}

	return time;
}

int main() {

	int appleX, appleY;
	int time;
	char dir;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> appleX >> appleY;
		map[appleX-1][appleY-1] = 1;
	}
	cin >> X;
	for (int i = 0; i < X; i++) {
		cin >> time >> dir;
		vec.push_back(make_pair(time, dir));
	}

	cout << solve();

	return 0;
}