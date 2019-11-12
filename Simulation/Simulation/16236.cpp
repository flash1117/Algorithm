#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x, y, sharkSize, kCnt;
}pos;

int N;
int map[21][21];

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int nFishX, nFishY, nCnt;

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

bool nextFish(int x, int y, int sharkSize) {

	queue <pos> temp;
	temp.push({ x,y,sharkSize, 0 });

	bool visited[21][21];
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			visited[i][j] = false;

	nFishX = 0; nFishY = 0; nCnt = 0;
	while (!temp.empty()) {

		pos tmp = temp.front();
		temp.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = tmp.x + dx[i];
			int nextY = tmp.y + dy[i];
			int sSize = tmp.sharkSize;
			int moveCnt = tmp.kCnt;
			
			if (isBoundary(nextX, nextY) && map[nextX][nextY] <= sSize && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
//				cout << nextX << " " << nextY << endl;
				if (map[nextX][nextY] == 0 || map[nextX][nextY] == sSize) {
					temp.push({ nextX, nextY, sSize, moveCnt+1 });
				}
				else {
					
					if (nFishX == 0 && nFishY == 0 && nCnt == 0) {
						nFishX = nextX;
						nFishY = nextY;
						nCnt = ++moveCnt;
					}
					else {

						if (nCnt <= moveCnt) return true;
						else {
							if (nextX < nFishX) {
								nFishX = nextX;
								nFishY = nextY;
							}
							else if (nextX == nFishX && nextY < nFishY) {
								nFishY = nextY;
							}
						}
					}
				}
			}
		}

	}

	if (nFishX == 0 && nFishY == 0 && nCnt == 0) return false;
	else return true;
}

int solve(int X, int Y) {

	int ret = 0;
	queue <pos> q;
	q.push({ X,Y,2,0 });

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int sSize = q.front().sharkSize;
		int ccnt = q.front().kCnt;
		map[curX][curY] = 0;

		q.pop();
//		cout << endl;
//		cout << "shark Size : " << sSize;
//		print();
		bool state = nextFish(curX, curY, sSize);
		if (!state) return ret;
		else {
		
			ccnt++;
			if (ccnt == sSize) {
				sSize++;
				ccnt = 0;
			}
			q.push({ nFishX,nFishY,sSize,ccnt });
			ret+= nCnt;
		}
	}

	return ret;
}


int main() {

	int x=0, y=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) { x = i; y = j; }
		}
	}

	cout << solve(x, y);

	return 0;
}