#include <iostream>
#include <queue>

using namespace std;

#define Endl "\n"

int N, M, diceX, diceY, K;
int map[21][21];
int order[1001];

int dice[] = { 0,0,0,0,0,0 };
int dx[] = { 0,0,-1,1 }; // µ¿ ¼­ ºÏ ³²
int dy[] = { 1,-1,0,0 };

typedef struct {

	int x, y, dir;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void diceChange(int direction) {
	int buf = 0;
	if (direction == 1) {

		buf = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = buf;
	}
	else if (direction == 2) {
		buf = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = buf;
	}
	else if (direction == 3) {
		buf = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = buf;
	}
	else if (direction == 4) {
		buf = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = buf;
	}
	else return;
}

void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << Endl;
	}
}

void solve() {

	int orderNum = 0;
	queue <pos> q;
	q.push({ diceX, diceY , order[0] });
	dice[5] = map[diceX][diceY];

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int curDir = q.front().dir;

		q.pop();

		if (orderNum > 0) {
			diceChange(curDir);
//			cout << dice[2] << Endl; // print top of dice
		}
		
		if (orderNum > 0 && map[curX][curY] == 0 && dice[5] != 0)
		{
			map[curX][curY] = dice[5];
			dice[5] = 0;
		}
		else if (map[curX][curY] != 0) {
			dice[5] = map[curX][curY];
			map[curX][curY] = 0;
		}

		cout << "current Direction : " << curDir << Endl;

		for (int i = 0; i < 6; i++)
			cout << dice[i] << " ";
		cout << Endl;

		print();

		for (int i = orderNum; i < K; i++) {
//			cout << "direction : " << order[orderNum] << Endl;
			
			int nextX = curX + dx[order[orderNum]-1];
			int nextY = curY + dy[order[orderNum]-1];
//			cout << nextX << " , " << nextY << Endl;
			if (isBoundary(nextX, nextY)) {
				q.push({ nextX, nextY, order[orderNum] });
				orderNum++;
				break;
			}
			else orderNum++;
		}		

	}



}


int main() {

	cin >> N >> M >> diceX >> diceY >> K;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
		cin >> order[i];

	solve();


	return 0;
}