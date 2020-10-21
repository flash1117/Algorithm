#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector <int> dir[17];
vector<pair<int, int>> pos[17];
int map[4][4];
pair<int, int> sharkPos;

int sharkDir, maxSum;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>3 || y>3) return false;
	return true;
}

int getDir(int index) {

	int _dir = dir[index].front();
	int curX = pos[index].front().first;
	int curY = pos[index].front().second;

	for (int i = _dir; i < 8; i++) {

		int nextX = curX + dx[i];
		int nextY = curY + dy[i];

		if (isBoundary(nextX, nextY) && nextX != sharkPos.first && nextY != sharkPos.second) {
			return i;
		}

	}

	for (int i = 0; i < _dir; i++) {

		int nextX = curX + dx[i];
		int nextY = curY + dy[i];

		if (isBoundary(nextX, nextY) && nextX != sharkPos.first && nextY != sharkPos.second) {
			return i;
		}

	}

	return -1;
}


void fishMove() {

	for (int i = 1; i <= 16; i++) {

		if (pos[i].front().first == -1) continue;

		int _dir = getDir(i);
		int curX = pos[i].front().first;
		int curY = pos[i].front().second;
		int nextX = curX + dx[_dir];
		int nextY = curY + dy[_dir];

		dir[i].front() = _dir;

		int dstFish = map[nextX][nextY];

		map[nextX][nextY] = map[curX][curY];
		map[curX][curY] = dstFish;

		pos[dstFish].front() = { curX, curY };
		pos[i].front() = { nextX, nextY };

	}

	return;

}

void print() {

	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void solve(int sum) {

	fishMove();
	print();
	int curSharkX = sharkPos.first;
	int curSharkY = sharkPos.second;

	for (int i = 0; i < 3; i++) {

		int nextSharkX = curSharkX + dx[sharkDir];
		int nextSharkY = curSharkY + dy[sharkDir];

		if (isBoundary(nextSharkX, nextSharkY) && map[nextSharkX][nextSharkY] != 0) {

			int dstFish = map[nextSharkX][nextSharkY];
			map[nextSharkX][nextSharkY] = 0;
			sharkPos.first = nextSharkX;
			sharkPos.second = nextSharkY;
			sharkDir = dir[dstFish].front();

			dir[dstFish].front() = -1;
			map[nextSharkX][nextSharkY] = 0;
			pos[dstFish].front() = { -1,-1 };
			
			maxSum = maxSum > (sum + dstFish) ? maxSum : (sum + dstFish);
			solve(sum + dstFish);

			dir[dstFish].front() = sharkDir;
			map[nextSharkX][nextSharkY] = dstFish;
			pos[dstFish].front() = { nextSharkX, nextSharkY };

		}
	}

	return;
}


int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			dir[a].push_back(b);
			map[i][j] = a;
			pos[a].push_back(make_pair(i, j));
		}
	}

	pos[map[0][0]].front() = { -1,-1 };
	sharkDir = dir[map[0][0]].front();
	maxSum = map[0][0];
	map[0][0] = 0;


	solve(maxSum);

	cout << maxSum << "\n";

	return 0;
}