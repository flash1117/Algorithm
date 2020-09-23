#include <iostream>
#include <vector>

int N, M, K;

using namespace std;

int map[20][20];
int smell[20][20];
int sharkDirection[401];
int directionPriority[401][4][4];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int sharkCnt;
pair<int, int> curSharkPos[401];
pair<int, int> sharkNextPos[401];

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}


int getEmptyDirection(int index) {

	int dir = sharkDirection[index] - 1;

	for (int i = 0; i < 4; i++) {
		int convertDir = directionPriority[index][dir][i]-1;
		int nextX = curSharkPos[index].first + dx[convertDir];
		int nextY = curSharkPos[index].second + dy[convertDir];

		if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && smell[nextX][nextY] == 0) {

			return convertDir;
		}


	}

	return -1;
}

void print() {
	cout << "\n";
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j++) {

			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cout << smell[i][j] << " ";
		}
		cout << "\n";
	}


}

void init() {

	for (int i = 1; i <= M; i++) {

		curSharkPos[i].first = -1;
		curSharkPos[i].second = -1;
	}
	return;
}

int getMySmellDirection(int index) {

	int dir = sharkDirection[index] - 1;

	for (int i = 0; i < 4; i++) {
		int convertDir = directionPriority[index][dir][i] - 1;
		int nextX = curSharkPos[index].first + dx[convertDir];
		int nextY = curSharkPos[index].second + dy[convertDir];

		if (isBoundary(nextX, nextY) && map[nextX][nextY] == index) {

			return convertDir;
		}


	}
	return -1;
}


int moveShark() {

	int moveCnt = 0;

	while (sharkCnt > 1) {
		//print();
		if (moveCnt >= 1000) return -1;
		moveCnt++;
		for (int i = 1; i <= M; i++) {

			if (curSharkPos[i].first == -1) continue;

			int emptyDir = getEmptyDirection(i);

			if (emptyDir != -1) {

				sharkNextPos[i].first = curSharkPos[i].first + dx[emptyDir];
				sharkNextPos[i].second = curSharkPos[i].second + dy[emptyDir];
				sharkDirection[i] = emptyDir + 1;

			}
			else { // 내 냄새 돌아가야함
				int mySmellDir = getMySmellDirection(i);

				if (mySmellDir != -1) {
					sharkNextPos[i].first = curSharkPos[i].first + dx[mySmellDir];
					sharkNextPos[i].second = curSharkPos[i].second + dy[mySmellDir];
					sharkDirection[i] = mySmellDir + 1;
				}
				else {
					sharkNextPos[i].first = curSharkPos[i].first;
					sharkNextPos[i].second = curSharkPos[i].second;
				}

			}

		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (smell[i][j] == 0) continue;
				else if (smell[i][j] == 1) {
					smell[i][j] = 0;
					map[i][j] = 0;
				}
				else {
					smell[i][j]--;
				}

			}
		}

		for (int i = 1; i <= M; i++) {

			if (curSharkPos[i].first == -1 || sharkNextPos[i].first == -1) continue;

			int nextX = sharkNextPos[i].first;
			int nextY = sharkNextPos[i].second;

			if (map[nextX][nextY] == 0) {

				map[nextX][nextY] = i;
				smell[nextX][nextY] = K;
				curSharkPos[i].first = nextX;
				curSharkPos[i].second = nextY;
			}
			else if (map[nextX][nextY] == i) {

				map[nextX][nextY] == i;
				smell[nextX][nextY] = K;
				curSharkPos[i].first = nextX;
				curSharkPos[i].second = nextY;
			}
			else if (map[nextX][nextY] > i) {
				sharkCnt--;
				curSharkPos[map[nextX][nextY]].first = -1;
				curSharkPos[map[nextX][nextY]].second = -1;
				sharkNextPos[map[nextX][nextY]].first = -1;
				sharkNextPos[map[nextX][nextY]].second = -1;

				map[nextX][nextY] = i;
				smell[nextX][nextY] = K;
				curSharkPos[i].first = nextX;
				curSharkPos[i].second = nextY;

			}
			else {
				sharkCnt--;
				curSharkPos[i].first = -1;
				curSharkPos[i].second = -1;
				sharkNextPos[i].first = -1;
				sharkNextPos[i].second = -1;
			}

		}


	}

	
	return moveCnt;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				sharkCnt++;
				smell[i][j] = K;
				curSharkPos[map[i][j]].first = i;
				curSharkPos[map[i][j]].second = j;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> sharkDirection[i];
	}

	for (int i = 1; i <= M; i++) {

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {

				cin >> directionPriority[i][j][k];
			}
		}

	}

	cout << moveShark() << "\n";
	return 0;
}
