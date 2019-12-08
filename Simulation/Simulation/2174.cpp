#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int x, y, direction;
}Robot;

typedef struct {
	int num;
	char ev;
	int cnt;
}Command;
vector <Robot> rob;
vector <Command> vec;

int map[101][101];

int dx[] = { -1,0,1,0 }; // 북 동 남 서
int dy[] = { 0,1,0,-1 }; // 시계 방향

int A, B, N, M;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>B - 1 || y>A - 1) return false;
	return true;
}

char chgDir(char curDir, char nextDir) {

	if (nextDir == 'L') {
		if (curDir == 'N') return 'W';
		else if (curDir == 'E') return 'N';
		else if (curDir == 'S') return 'E';
		else return 'S';
	}
	else if (nextDir == 'R') {
		if (curDir == 'N') return 'E';
		else if (curDir == 'E') return 'S';
		else if (curDir == 'S') return 'W';
		else return 'N';
	}
	
}

int setDir(char dir) {
	if (dir == 'N') return 0;
	else if (dir == 'E') return 1;
	else if (dir == 'S') return 2;
	else return 3;
}

void solve() {

	queue <Robot> q;
	
	for (int i = 0; i < vec.size(); i++) {

		if (!q.empty()) for (int i = 0; i < q.size(); i++) q.pop();	
		q.push({ rob[vec[i].num].x, rob[vec[i].num].y, rob[vec[i].num].direction });
		while (vec[i].cnt--) {

			int curX = q.front().x;
			int curY = q.front().y;
			int dir = q.front().direction;

			q.pop();

			if (vec[i].ev == 'F') {
				int mdir = setDir(dir);
				int nextX = curX + dx[mdir];
				int nextY = curY + dy[mdir];

				if (isBoundary(nextX, nextY)) {

					for (int j = 0; j < rob.size(); j++) {
						if (j != vec[i].num && nextX == rob[j].x && nextY == rob[j].y)
						{
							cout << "Robot " << vec[i].num+1 << " crashes into robot " << j+1 <<"\n";
							return;
						}
					}
					q.push({ nextX, nextY, dir });
					rob[vec[i].num].x = nextX;
					rob[vec[i].num].y = nextY;
				}
				else {
					cout << "Robot " << vec[i].num + 1 << " crashes into the wall\n";
					return;
				}
				
			}
			else {
				dir = chgDir(dir, vec[i].ev);
				q.push({ curX, curY, dir });
				rob[vec[i].num].direction = dir;
			}

		}
	}

	cout << "OK\n";
	return;
}

int main() {
	int input1, input2;
	char d;

	cin >> A >> B;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input1 >> input2 >> d;
		input1 -= 1;
		input2 = B - input2;
		rob.push_back({ input2, input1, chgDir(d,'R') });
	}
	for (int i = 0; i < M; i++) {
		cin >> input1 >> d >> input2;
		vec.push_back({ input1-1, d, input2 });
	}

	solve();

	return 0;
}