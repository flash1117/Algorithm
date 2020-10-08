#include <iostream>
#include <vector>


using namespace std;

typedef struct {

	int x, y, dir;
}Chess;

int N, K;
int map[13][13];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
vector<int> pos[15][15];
vector<Chess> vec[15];


bool isBoundary(int x, int y) {
	if (x<1 || y<1 || x>N || y>N) return false;
	return true;
}

bool isCanEnd() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (pos[i][j].size() >= 4) return true;
		}
	}

	return false;
}

int getChgDir(int dir) {

	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;

}

int solve() {

	int cnt = 1;
	if (isCanEnd()) return cnt;

	while (cnt) {

		if (cnt > 1000) return -1;

		for (int i = 1; i <= K; i++) {
			vector <int> stack; //이동하고자 하는 곳의 위에 쌓여있는 애들
			int curX = vec[i].front().x;
			int curY = vec[i].front().y;
			int dir = vec[i].front().dir;

			bool state = false;
			for (int j = 0; j < pos[curX][curY].size(); j++) {
				if (pos[curX][curY][j] == i)
				{
					state = true;
				
				}

				if (state) stack.push_back(pos[curX][curY][j]);
			}

			int nextX = curX + dx[dir];
			int nextY = curY + dy[dir];

			if (isBoundary(nextX, nextY)) {

				if (map[nextX][nextY] == 1) { // 빨강

					for (int j = stack.size() - 1; j >= 0; j--) {
						pos[nextX][nextY].push_back(stack[j]);
						vec[stack[j]].front().x = nextX;
						vec[stack[j]].front().y = nextY;

					}

					if (pos[nextX][nextY].size() >= 4) return cnt;

					for (int j = 0; j < stack.size(); j++)
						pos[curX][curY].pop_back();

				}
				else if (map[nextX][nextY] == 2) { // 파랑

					dir = getChgDir(dir);
					nextX = curX + dx[dir];
					nextY = curY + dy[dir];
					vec[i].front().dir = dir;

					if (isBoundary(nextX, nextY)) {

						
						if(map[nextX][nextY] == 1) {

							for (int j = stack.size() - 1; j >= 0; j--) {
								pos[nextX][nextY].push_back(stack[j]);
								vec[stack[j]].front().x = nextX;
								vec[stack[j]].front().y = nextY;

							}
							if (pos[nextX][nextY].size() >= 4) return cnt;
							for (int j = 0; j < stack.size(); j++)
								pos[curX][curY].pop_back();
						}
						else if(map[nextX][nextY] == 0){

							for (int j = 0; j < stack.size(); j++) {
								pos[nextX][nextY].push_back(stack[j]);
								vec[stack[j]].front().x = nextX;
								vec[stack[j]].front().y = nextY;

							}
							if (pos[nextX][nextY].size() >= 4) return cnt;
							for (int j = 0; j < stack.size(); j++)
								pos[curX][curY].pop_back();
						}

					}
					else {
						vec[i].front().dir = dir;
					}

				}
				else { // map = 0
					for (int j = 0; j <stack.size(); j++) {
						pos[nextX][nextY].push_back(stack[j]);
						vec[stack[j]].front().x = nextX;
						vec[stack[j]].front().y = nextY;

					}
					if (pos[nextX][nextY].size() >= 4) return cnt;
					for (int j = 0; j < stack.size(); j++)
						pos[curX][curY].pop_back();
				}

			}
			else { // 영역 밖일 때

				dir = getChgDir(dir);
				nextX = curX + dx[dir];
				nextY = curY + dy[dir];

				if (map[nextX][nextY] == 2) {
					vec[i].front().dir = dir;
				}
				else if (map[nextX][nextY] == 1) {
					vec[i].front().dir = dir;

					for (int j = stack.size() - 1; j >= 0; j--) {
						pos[nextX][nextY].push_back(stack[j]);
						vec[stack[j]].front().x = nextX;
						vec[stack[j]].front().y = nextY;

					}
					if (pos[nextX][nextY].size() >= 4) return cnt;
					for (int j = 0; j < stack.size(); j++)
						pos[curX][curY].pop_back();
				}
				else { // 0
					vec[i].front().dir = dir;
					for (int j = 0; j < stack.size(); j++) {
						pos[nextX][nextY].push_back(stack[j]);
						vec[stack[j]].front().x = nextX;
						vec[stack[j]].front().y = nextY;

					}
					if (pos[nextX][nextY].size() >= 4) return cnt;
					for (int j = 0; j < stack.size(); j++)
						pos[curX][curY].pop_back();
				}

			}

			stack.clear();
		}

		cnt++;
	}



	return cnt;
}



int main() {

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
		 
	}

	for (int i = 1; i <= K; i++) {

		int x, y, d;
		cin >> x >> y >> d;

		vec[i].push_back({ x,y,d });
		pos[x][y].push_back(i);
	}

	cout << solve() << "\n";

	return 0;
}