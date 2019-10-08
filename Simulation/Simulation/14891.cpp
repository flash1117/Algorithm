#include <iostream>

using namespace std;

int Gear[8][4];
int pos[101], dir[101],K;

// N 극은 0, S는 1

void moveGear(int position ,int direction) {
	
	int buf = Gear[0][position];
	
	if (direction == -1) { // 반시계 방향

		Gear[0][position] = Gear[1][position];
		Gear[1][position] = Gear[2][position];
		Gear[2][position] = Gear[3][position];
		Gear[3][position] = Gear[4][position];
		Gear[4][position] = Gear[5][position];
		Gear[5][position] = Gear[6][position];
		Gear[6][position] = Gear[7][position];
		Gear[7][position] = buf;

	}
	else if (direction == 1) { // 시계 방향

		Gear[0][position] = Gear[7][position];
		Gear[7][position] = Gear[6][position];
		Gear[6][position] = Gear[5][position];
		Gear[5][position] = Gear[4][position];
		Gear[4][position] = Gear[3][position];
		Gear[3][position] = Gear[2][position];
		Gear[2][position] = Gear[1][position];
		Gear[1][position] = buf;

	}

}

bool stateCheck(int position, int dir) { // 주변 톱니바퀴 상태 체크
	// 맞닿는 부분은 index 2, 6

	if (position < 0 || position >3) return false;
	if (dir == -1)
		if (Gear[2][position] == Gear[6][position + 1]) return false;
	else if (dir == 1)
		if (Gear[6][position] == Gear[2][position - 1]) return false;
	return true;
}

int solve() {

	int sum = 0;
	for (int i = 0; i < K; i++) {

		int cur = pos[i] - 1;
		bool Left = stateCheck(cur - 1, -1);
		bool Right = stateCheck(cur + 1, 1);
		bool LLeft = false, RRight = false;

		moveGear(cur, dir[i]); 
		if (Left) {

			LLeft = stateCheck(cur - 2, -1);
			moveGear(cur - 1, -dir[i]);
			if (LLeft) moveGear(cur - 2, dir[i]);
		}
		if (Right) {

			RRight = stateCheck(cur + 2, 1);
			moveGear(cur + 1, -dir[i]);
			if (RRight) moveGear(cur + 2, dir[i]);
		}

	}

	for (int j = 0; j < 4; j++) {

		if (Gear[0][j] > 0) {
			if (j == 0) sum += 1;
			else if (j == 1) sum += 2;
			else if (j == 2) sum += 4;
			else if (j == 3) sum += 8;

		}
	}
	return sum;
}


int main() {

	string temp;

	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			Gear[j][i] = temp[j] - '0';
		
		}
			
	}
			
	cin >> K;

	for (int i = 0; i < K; i++)
		cin >> pos[i] >> dir[i];

	cout << solve();
	return 0;
}