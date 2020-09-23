#include <iostream>
#include <vector>

using namespace std;

typedef struct {

	int x, y, dir;
}Fish;


int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

int map[4][4];
Fish fish[17];
Fish shark;
int sharkEat;

bool isBoundary(int x, int y) {

	if (x < 0 || y < 0 || x>3 || y>3) return false;
	return true;

}

int getMoveDir(int index) {

	for (int i = fish[index].dir - 1; i < 8; i++) {

		int nextX = fish[index].x + dx[i];
		int nextY = fish[index].y + dy[i];

		if (nextX == shark.x && nextY == shark.y) continue;
		else if (isBoundary(nextX, nextY)) {

			return i;
		}

	}

	for (int i = 0; i < fish[index].dir - 1; i++) {
		
		int nextX = fish[index].x + dx[i];
		int nextY = fish[index].y + dy[i];

		if (nextX == shark.x && nextY == shark.y) continue;
		else if (isBoundary(nextX, nextY)) {

			return i;
		}
	}


	return -1;
}

void printMap() {
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void printFish() {

	cout << "\n";
	for (int i = 1; i <= 16; i++) {
		cout << fish[i].x << "," << fish[i].y << " " << fish[i].dir << "\n";
	}
}

void moveFish(int sum) {

	sharkEat = sharkEat > sum ? sharkEat : sum;
	
	for (int i = 1; i <= 16; i++) { // map 구성

		if (fish[i].dir == -1) continue;

		int nextDir = getMoveDir(i);
		if (nextDir != -1) { // 움직일 수 있을 때

			int nextX = fish[i].x + dx[nextDir];
			int nextY = fish[i].y + dy[nextDir];

			if (map[nextX][nextY] == 0) {

				map[fish[i].x][fish[i].y] = 0;
				fish[i].x = nextX;
				fish[i].y = nextY;
				fish[i].dir = nextDir + 1;
				map[fish[i].x][fish[i].y] = i;
				
			}
			else { // 물고기가 있을 때

				map[fish[i].x][fish[i].y] = map[nextX][nextY];

				fish[map[nextX][nextY]].x = fish[i].x;
				fish[map[nextX][nextY]].y = fish[i].y;

				fish[i].x = nextX;
				fish[i].y = nextY;
				fish[i].dir = nextDir + 1;

				map[nextX][nextY] = i;

			}


		}
	}

	for (int i = 1; i <= 3; i++) {

		int nSharkX = shark.x + dx[shark.dir - 1]*i;
		int nSharkY = shark.y + dy[shark.dir - 1] * i;

		if (!isBoundary(nSharkX, nSharkY)) break;
		else if (map[nSharkX][nSharkY] == 0) continue;

		Fish tempFish[17];
		for (int i = 1; i < 17; i++) {
			tempFish[i] = fish[i];
		}

		Fish tempShark = { shark.x, shark.y, shark.dir };


		shark.x = nSharkX;
		shark.y = nSharkY;
		shark.dir = fish[map[shark.x][shark.y]].dir;
		int eat = sum + map[shark.x][shark.y];
		fish[map[shark.x][shark.y]].x = -1;
		fish[map[shark.x][shark.y]].y = -1;
		fish[map[shark.x][shark.y]].dir = -1;
		map[shark.x][shark.y] = 0;

		
		//cout << "sum : " << eat << "\n";
		//printMap();
		
		
		moveFish(eat);


		int tempMap[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tempMap[i][j] = 0;
			}
		}

		for (int i = 1; i < 17; i++) {
			fish[i] = tempFish[i];
		}

		for (int i = 1; i < 17; i++) {

			if (fish[i].dir == -1 || fish[i].x == -1) continue;

			tempMap[fish[i].x][fish[i].y] = i;
		}
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = tempMap[i][j];
			}
		}

		shark = tempShark;
		//cout << "sum : " << eat << "\n";
		//printMap();
	}

	return;
}



int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int input;
			cin >> input;
			if (j % 2 == 0) {
				map[i][j/2] = input;
				fish[input].x = i;
				fish[input].y = j/2;
			}
			else fish[map[i][j/2]].dir = input;
		}
	}
	int firstEat = map[0][0];
	shark.x = 0;
	shark.y = 0;
	shark.dir = fish[map[0][0]].dir;

	fish[map[0][0]].x = -1;
	fish[map[0][0]].y = -1;
	fish[map[0][0]].dir = -1;
	map[0][0] = 0;

	if (firstEat == 0) cout << 0 << "\n";
	else moveFish(firstEat);

	cout << sharkEat << "\n";

	return 0;
}