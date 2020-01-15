#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int y, x;
	char dir;
}pos; // �κ� ��ǥ

typedef struct{
	int index; // �κ� ��ȣ
	char od; // ��� R, L , F
	int re; // �ݺ�Ƚ��
}_order; // ���

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

	if (_od == 'R') { // ���� ���⿡�� ������ �������� 90�� ��ŭ ȸ��
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

	for (int i = 0; i < order.size(); i++) { // ����� ������ŭ
		
		int robot_index = order[i].index - 1; 
		// input���� ������ index�� 1�������� vector�� �̷���� robot���� index������ 0���� �����ؼ�
		char d = robot[robot_index].dir;
		char moveOrder = order[i].od; // R , L , F ���
		int repeatCnt = order[i].re; // ��� �ݺ�Ƚ��

		if(moveOrder == 'F') { // ����
			
			int curX = robot[robot_index].x; // current X
			int curY = robot[robot_index].y; // current Y
			int cdir = convertDir(robot[robot_index].dir); // current direction

			for (int j = 0; j < repeatCnt; j++) {

				int nextX = curX + dx[cdir];
				int nextY = curY + dy[cdir];

				if (isBoundary(nextX, nextY) && map[nextX][nextY] != 0) { 
					// ���� �������� ������ �ϴ� map�� �ٸ� index�� �ִ� ���
					cout << "Robot " << robot_index+1 << " crashes into robot " << map[nextX][nextY] << "\n";
					return false;
				}
				else if (!isBoundary(nextX, nextY)) { // ���� ������ ������ �� -> ���� �ε���
					cout << "Robot " << robot_index+1 << " crashes into the wall\n";
					return false;
				}
				else if(map[nextX][nextY] == 0 && isBoundary(nextX, nextY)) {
					map[nextX][nextY] = map[curX][curY]; // ĭ �̵�
					map[curX][curY] = 0; // ���� �ִ� ĭ ����
					curX = nextX; curY = nextY; // curreent position update
				}
			}

		}
		else { // R�̳� L ���
			for (int j = 0; j < repeatCnt; j++) { // �ݺ���� Ƚ����ŭ
				d = changeDir(moveOrder, d); // ���� direction�� ��ɿ� ���� ȸ��
			}
			robot[robot_index].dir = d; // �ݺ� ���Ƚ����ŭ �޶��� direction�� update
		}
	}
	return true; // ���������� ����
}

int main() {

	cin >> A >> B; // B�� ��, A�� ��
	cin >> N >> M; 
	for (int i = 1; i <= N; i++) { // N ��ŭ �κ��� �Է¹���
		pos input;
		cin >> input.y >> input.x >> input.dir;
		input.y--;  // (0,0) ���� �����ϱ� ���ؼ�
		input.x = B - input.x;
		robot.push_back(input);
		map[input.x][input.y] = i;
	}
	for (int i = 0; i < M; i++) { // M��ŭ ����� �Է¹���
		_order input;
		cin >> input.index >> input.od >> input.re;
		order.push_back(input);
	}

	if (solve()) cout << "OK\n"; // return true
	
	return 0;
}