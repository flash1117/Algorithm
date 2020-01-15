#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int y, x;
	char dir;
}pos; // 로봇 좌표

typedef struct{
	int index; // 로봇 번호
	char od; // 명령 R, L , F
	int re; // 반복횟수
}_order; // 명령

int A, B, N, M;
int map[101][101];

int dx[] = { -1,0,1,0 }; // north , east, south, west
int dy[] = { 0,1,0,-1 };

vector <pos> robot;
vector <_order> order;

void print() {
	cout << endl;
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < A; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>B - 1 || y>A - 1) return false;
	return true;
}

int convertDir(char dir) {

	if (dir == 'N') return 0;
	else if (dir == 'E') return 1;
	else if (dir == 'S') return 2;
	else if (dir == 'W') return 3;

}

char changeDir(char _od, char currentDir) {

	if (_od == 'R') { // 현재 방향에서 오른쪽 방향으로 90도 만큼 회전
		if (currentDir == 'N') return 'E';
		else if (currentDir == 'E') return 'S';
		else if (currentDir == 'S') return 'W';
		else if (currentDir == 'W') return 'N';
	}
	else if (_od == 'L') {
		if (currentDir == 'N') return 'W';
		else if (currentDir == 'W') return 'S';
		else if (currentDir == 'S') return 'E';
		else if (currentDir == 'E') return 'N';
	}
}

bool solve() {

	for (int i = 0; i < order.size(); i++) { // 명령의 갯수만큼
		
		int robot_index = order[i].index - 1; 
		// input으로 들어오는 index는 1부터지만 vector로 이루어진 robot에는 index참조가 0부터 시작해서
		char d = robot[robot_index].dir;
		char moveOrder = order[i].od; // R , L , F 명령
		int repeatCnt = order[i].re; // 명령 반복횟수

		if(moveOrder == 'F') { // 전진
			
			int curX = robot[robot_index].x; // current X
			int curY = robot[robot_index].y; // current Y
			int cdir = convertDir(robot[robot_index].dir); // current direction

			for (int j = 0; j < repeatCnt; j++) {

				int nextX = curX + dx[cdir];
				int nextY = curY + dy[cdir];

				if (isBoundary(nextX, nextY) && map[nextX][nextY] != 0) { 
					// 영역 안이지만 가고자 하는 map에 다른 index가 있는 경우
					cout << "Robot " << robot_index+1 << " crashes into robot " << map[nextX][nextY] << "\n";
					return false;
				}
				else if (!isBoundary(nextX, nextY)) { // 영역 밖으로 나갔을 때 -> 벽에 부딪힘
					cout << "Robot " << robot_index+1 << " crashes into the wall\n";
					return false;
				}
				else if(map[nextX][nextY] == 0 && isBoundary(nextX, nextY)) {
					map[nextX][nextY] = map[curX][curY]; // 칸 이동
					map[curX][curY] = 0; // 전에 있던 칸 비우기
					curX = nextX; curY = nextY; // curreent position update
				}
			}

		}
		else { // R이나 L 명령
			for (int j = 0; j < repeatCnt; j++) { // 반복명령 횟수만큼
				d = changeDir(moveOrder, d); // 현재 direction을 명령에 따라 회전
			}
			robot[robot_index].dir = d; // 반복 명령횟수만큼 달라진 direction을 update
		}
	}
	return true; // 성공적으로 종료
}

int main() {

	cin >> A >> B; // B가 행, A가 열
	cin >> N >> M; 
	for (int i = 1; i <= N; i++) { // N 만큼 로봇을 입력받음
		pos input;
		cin >> input.y >> input.x >> input.dir;
		input.y--;  // (0,0) 부터 시작하기 위해서
		input.x = B - input.x;
		robot.push_back(input);
		map[input.x][input.y] = i;
	}
	for (int i = 0; i < M; i++) { // M만큼 명령을 입력받음
		_order input;
		cin >> input.index >> input.od >> input.re;
		order.push_back(input);
	}

	if (solve()) cout << "OK\n"; // return true
	
	return 0;
}