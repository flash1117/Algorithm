#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int x, y, dir;
}Pos;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int map[4][4];
int copyMap[4][4][1000];
int ret = 0;
vector <Pos> fishPos[17], copyFishPos[17][1000]; // fish direction
Pos shark;

void print() {
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

}

void fishDirPrint() {

	for (int i = 1; i < 17; i++) {

		if (fishPos[i].empty()) {
			cout << i << "번째 Fish 는 없습니다.\n";
		}
		else cout << i << "번째 Fish Dir = " << fishPos[i][0].dir << "\n";
	}
}

bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>3 || y>3) return false;
	return true;
}

void fishMove() {

	for (int i = 1; i < 17; i++) {

		if (!fishPos[i].empty()) {

			int nextX = fishPos[i][0].x + dx[fishPos[i][0].dir - 1];
			int nextY = fishPos[i][0].y + dy[fishPos[i][0].dir - 1];

			if ((nextX != shark.x || nextY != shark.y) && isBoundary(nextX, nextY)) {
				// 상어가 있는 칸이 아니면서 영역 안일 경우

				if (map[nextX][nextY] != 0) { // 이동 할 곳에 물고기가 있는 경우
					fishPos[map[nextX][nextY]][0].x = fishPos[i][0].x;
					fishPos[map[nextX][nextY]][0].y = fishPos[i][0].y;
					map[fishPos[i][0].x][fishPos[i][0].y] = map[nextX][nextY];
					fishPos[i][0].x = nextX;
					fishPos[i][0].y = nextY;
					map[nextX][nextY] = i;
				}
				else { // 비어 있는 경우
					map[nextX][nextY] = i;
					map[fishPos[i][0].x][fishPos[i][0].y] = 0;
					fishPos[i][0].x = nextX;
					fishPos[i][0].y = nextY;

				}

			}
			else { // 진행 방향에 상어가 있거나 boundary 밖일 경우

				while (1) {
					if (fishPos[i][0].dir == 8) fishPos[i][0].dir = 1;
					else fishPos[i][0].dir++;

					nextX = fishPos[i][0].x + dx[fishPos[i][0].dir - 1];
					nextY = fishPos[i][0].y + dy[fishPos[i][0].dir - 1];

					if ((nextX != shark.x || nextY != shark.y) && isBoundary(nextX, nextY)) break;
				}

				if (map[nextX][nextY] != 0) { // 이동 할 곳에 물고기가 있는 경우
					fishPos[map[nextX][nextY]][0].x = fishPos[i][0].x;
					fishPos[map[nextX][nextY]][0].y = fishPos[i][0].y;
					map[fishPos[i][0].x][fishPos[i][0].y] = map[nextX][nextY];
					fishPos[i][0].x = nextX;
					fishPos[i][0].y = nextY;
					map[nextX][nextY] = i;
				}
				else { // 비어 있는 경우
					map[nextX][nextY] = i;
					map[fishPos[i][0].x][fishPos[i][0].y] = 0;
					fishPos[i][0].x = nextX;
					fishPos[i][0].y = nextY;

				}
			}
		}
	}

}

void mapToCopy(int depth) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copyMap[i][j][depth] = map[i][j];
		}
	}
}
void fishToCopy(int depth) {
	
	for (int i = 1; i < 17; i++) {

		if (fishPos[i].empty() && !copyFishPos[i][depth].empty()) 
			copyFishPos[i][depth].pop_back();
		else if(!fishPos[i].empty() && copyFishPos[i][depth].empty()){
			copyFishPos[i][depth].push_back(fishPos[i][0]);
		}
		else if(!fishPos[i].empty() && !copyFishPos[i][depth].empty()){
			copyFishPos[i][depth][0] = fishPos[i][0];
		}
	}
}
void copyToMap(int depth) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = copyMap[i][j][depth];
		}
	}
}
void copyToFish(int depth) {

	for (int i = 1; i < 17; i++) {

		if (copyFishPos[i][depth].empty() && !fishPos[i].empty())
			fishPos[i].pop_back();
		else if(!copyFishPos[i][depth].empty() && fishPos[i].empty()){
			fishPos[i].push_back(copyFishPos[i][depth][0]);
		}
		else if(!copyFishPos[i][depth].empty() && !fishPos[i].empty()){
			fishPos[i][0] = copyFishPos[i][depth][0];
		}
	}

}
void sharkMove(int sharkX, int sharkY, int sharkDir, int eatFish, int depth) {
	
	if (!isBoundary(sharkX, sharkY)) {
		ret = ret > eatFish ? ret : eatFish;
		return;
	}

	int nextX = sharkX + dx[sharkDir-1];
	int nextY = sharkY + dy[sharkDir-1];

	if (map[nextX][nextY] == 0) return;

	int curFish = map[nextX][nextY];
	cout << "depth  : " << depth << "curFish : " << curFish << "eatFish : " << eatFish << "\n";
	Pos temp = {0,0,0};

	if (!fishPos[map[nextX][nextY]].empty()) {
		temp = fishPos[map[nextX][nextY]].front();
		fishPos[map[nextX][nextY]].pop_back();
	}
		
	map[nextX][nextY] = 0;
	sharkDir = temp.dir;

	mapToCopy(depth);
	fishToCopy(depth);

	fishMove();
	
	sharkMove(nextX, nextY,sharkDir,eatFish+curFish, depth+1);
	copyToMap(depth);
	copyToFish(depth);
	nextX += dx[shark.dir];
	nextY += dy[shark.dir]; 
	sharkMove(nextX, nextY,sharkDir, eatFish+curFish, depth+1);
	copyToMap(depth);
	copyToFish(depth);
	nextX += dx[shark.dir];
	nextY += dy[shark.dir];
	sharkMove(nextX, nextY, sharkDir, eatFish+curFish, depth+1);
	copyToMap(depth);
	copyToFish(depth);
	return;
}

int main() {
	int input;
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		for (int j = 0; j < 8; j++) {
			cin >> input;
			if (cnt++ % 2 == 0) {
				map[i][j / 2] = input;
			}
			else {
				fishPos[map[i][j / 2]].push_back({i,j/2,input});
			}

		}
	}

	// shark eat first fish
	int eatFish = map[0][0];
	shark.dir = fishPos[map[0][0]][0].dir;
	fishPos[map[0][0]].pop_back();
	map[0][0] = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copyMap[i][j][0] = map[i][j];
		}
	}

	fishMove();
	sharkMove(0,0,shark.dir,eatFish,0);
	cout << ret << "\n";
	return 0;
}