#include <iostream>
#include <vector>

using namespace std;

// 정면에서 바라보는 큐브를 기준
// U : 윗면, D : 아랫면 F : 앞면 B : 뒷면 L : 왼쪽 면 R : 오른쪽 면
// 흰색, 노랑, 빨강 , 오렌지, 초록, 파랑 
// +는 시계방향 -는 반시계 방향

int T, N;
char cube[6][3][3];
vector <string> vec;

void initCube() {

	char color;
	for (int i = 0; i < 6; i++) {

		if (i == 0) color = 'w';
		else if (i == 1) color = 'y';
		else if (i == 2) color = 'r';
		else if (i == 3) color = 'o';
		else if (i == 4) color = 'g';
		else if (i == 5) color = 'b';

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = color;
			}
		}
	}
}

void rotateCube(string command) {

	if (command[1] == '-') {

		if (command[0] == 'U') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[2][0][i];
				cube[2][0][i] = cube[5][0][i];
				cube[5][0][i] = cube[3][0][i];
				cube[3][0][i] = cube[4][0][i];
				cube[4][0][i] = temp;
			}
		}
		else if (command[0] == 'D') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[2][2][i];
				cube[2][2][i] = cube[4][2][i];
				cube[4][2][i] = cube[3][2][i];
				cube[3][2][i] = cube[5][2][i];
				cube[5][2][i] = temp;
			}
		}
		else if (command[0] == 'F') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][2][i];
				cube[0][2][i] = cube[5][i][0];
				cube[5][i][0] = cube[1][2][i];
				cube[1][2][i] = cube[4][i][2];
				cube[4][i][2] = temp;
			}
		}
		else if (command[0] == 'B') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][0][i];
				cube[0][0][i] = cube[4][i][0];
				cube[4][i][0] = cube[1][0][i];
				cube[1][0][i] = cube[5][i][2];
				cube[5][i][2] = temp;
			}
		}
		else if (command[0] == 'L') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][i][0];
				cube[0][i][0] = cube[2][i][0];
				cube[2][i][0] = cube[1][i][0];
				cube[1][i][0] = cube[3][i][0];
				cube[3][i][0] = temp;
			}
		}
		else if (command[0] == 'R') {

			for (int i = 0; i < 3; i++) {
				char temp = cube[0][i][2];
				cube[0][i][2] = cube[3][i][2];
				cube[3][i][2] = cube[1][i][2];
				cube[1][i][2] = cube[2][i][2];
				cube[2][i][2] = temp;
			}
		}

	}
	else if (command[1] == '+') {

		if (command[0] == 'U') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[2][0][i];
				cube[2][0][i] = cube[4][0][i];
				cube[4][0][i] = cube[3][0][i];
				cube[3][0][i] = cube[5][0][i];
				cube[5][0][i] = temp;
			}
		}
		else if (command[0] == 'D') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[2][2][i];
				cube[2][2][i] = cube[5][2][i];
				cube[5][2][i] = cube[3][2][i];
				cube[3][2][i] = cube[4][2][i];
				cube[4][2][i] = temp;
			}
		}
		else if (command[0] == 'F') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][2][i];
				cube[0][2][i] = cube[4][i][2];
				cube[4][i][2] = cube[1][2][i];
				cube[1][2][i] = cube[5][i][0];
				cube[5][i][0] = temp;
				
			}
		}
		else if (command[0] == 'B') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][0][i];
				cube[0][0][i] = cube[5][i][2];
				cube[5][i][2] = cube[1][0][i];
				cube[1][0][i] = cube[4][i][0];
				cube[4][i][0] = temp;
			}
		}
		else if (command[0] == 'L') {
			
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][i][0];
				cube[0][i][0] = cube[3][i][0];
				cube[3][i][0] = cube[1][i][0];
				cube[1][i][0] = cube[2][i][0];
				cube[2][i][0] = temp;
			}
			
		}
		else if (command[0] == 'R') {
			for (int i = 0; i < 3; i++) {
				char temp = cube[0][i][2];
				cube[0][i][2] = cube[2][i][2];
				cube[2][i][2] = cube[1][i][2];
				cube[1][i][2] = cube[3][i][2];
				cube[3][i][2] = temp;
			}
		}
	}

}

void printUCube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << "\n";
	}
}

int main() {

	string temp;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			vec.push_back(temp);
		}
		initCube();
		for (int i = 0; i < vec.size(); i++)
			rotateCube(vec[i]);
		printUCube();
		vec.clear();
	}

	return 0;
}