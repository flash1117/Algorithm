#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int r, c, s, d, z;
}Shark;

int R, C, M;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int map[101][101];
vector<Shark> sh[10001];
vector<int> sharkQueue;

void initMap() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = 0;
		}
	}
	return;
}


void print() {
	cout << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void sharkMove() {
	vector<Shark> vec;

	for (int i = 0; i < sharkQueue.size(); i++) {

		int curShark = sharkQueue[i];
		if (sh[curShark][0].r == 0) continue;

		int curX = sh[curShark][0].r;
		int curY = sh[curShark][0].c;
		int dir = sh[curShark][0].d;
		int speed = sh[curShark][0].s;
		map[curX][curY] = 0;
		
		if (dir == 1 || dir == 2) {
			int nextX = curX;
			speed %= 2 * (R-1);
			while (speed--) {

				nextX += dx[dir];
				if (nextX == 0) {
					nextX = 2;
					dir = 2;
					
				}
				else if (nextX == R + 1) {
					nextX = R - 1;
					dir = 1;
				}
				
			}


			vec.push_back({ nextX, curY, sh[curShark][0].s , dir, sh[curShark][0].z });
		}
		else {

			int nextY = curY;
			speed %= 2 * (C-1);
			while (speed--) {

				nextY += dy[dir];
				if (nextY == 0) {
					nextY = 2;
					dir = 3;

				}
				else if (nextY == C + 1) {
					nextY = C - 1;
					dir = 4;
				}

			}
			vec.push_back({ curX, nextY, sh[curShark][0].s , dir, sh[curShark][0].z });
		}


	}

	for (int i = 0; i < vec.size(); i++) {

		sh[vec[i].z][0] = { vec[i].r, vec[i].c, vec[i].s, vec[i].d, vec[i].z };

		if (map[vec[i].r][vec[i].c] == 0) {
			map[vec[i].r][vec[i].c] = vec[i].z;
		}
		else {

			if (map[vec[i].r][vec[i].c] > vec[i].z) {

				sh[vec[i].z][0] = { 0,0,0,0,0 };
			}
			else {

				sh[map[vec[i].r][vec[i].c]][0] = { 0,0,0,0,0 };
				map[vec[i].r][vec[i].c] = vec[i].z;
			}
		}
	}
	return;
}


int getShark() {
	int sum = 0;
	for (int j = 1; j <= C; j++) {

		for (int i = 1; i <= R; i++) {

			if (map[i][j] != 0) {
				sh[map[i][j]][0] = { 0,0,0,0,0 };
				sum += map[i][j];
				map[i][j] = 0;
				break;
			}

		}
	//	print();
		sharkMove();


	}

	return sum;

}



int main() {
	

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		Shark input;
		cin >> input.r >> input.c >> input.s >> input.d >> input.z;
		sh[input.z].push_back(input);
		map[input.r][input.c] = input.z;
		sharkQueue.push_back(input.z);
	}

	cout << getShark() << "\n";

	return 0;
}