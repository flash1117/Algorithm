#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Gear[4][9]; // N = 0 , S = 1
int K;
vector <pair<int, int>>  vec;
bool isMove[4];

void moveGear(int index , int direction) {

	if (direction == -1) { // 반시계
		int temp = Gear[index][0];
		for (int i = 1; i < 8; i++) 
			Gear[index][i-1] = Gear[index][i];
		Gear[index][7] = temp;
	}
	else { // 시계
		int temp = Gear[index][7];
		for (int i = 7; i >0; i--) {
			Gear[index][i] = Gear[index][i - 1];
		}
		Gear[index][0] = temp;
	}
	return;
}

int solve() {
	// 2는 오른쪽 6은 왼쪽
	for (int i = 0; i < vec.size(); i++) {

		for (int j = 0; j < 4; j++) // init
			isMove[j] = false;

		isMove[vec[i].first - 1] = true;
		for (int j = vec[i].first - 2; j >= 0 && j < 3; j--) {

			if (Gear[j][2] == Gear[j + 1][6]);
			else {
				if (isMove[j + 1]) isMove[j] = true;
				else break;
			}
			
		}
		for (int j = vec[i].first; j <= 3 && j >0; j++) {

			if (Gear[j][6] == Gear[j - 1][2]);
			else {
				if (isMove[j - 1]) isMove[j] = true;
				else break;
			}
		}

		int dir = vec[i].second;
		for (int j = vec[i].first - 1; j <= 3; j++) {
			if (isMove[j]) {
				moveGear(j, dir);
				dir *= -1;
			}
			else break;
		}
		dir = vec[i].second * (-1);
		for (int j = vec[i].first - 2; j >= 0; j--) {
			if (isMove[j]) {
				moveGear(j, dir);
				dir *= -1;
			}
			else break;
		}
	}

	int ret = 0;
	int score = 1;
	for (int i = 0; i < 4; i++) {
		ret += Gear[i][0] * score;
		score *= 2;
	}
	return ret;

}

int main() {

	string temp;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			Gear[i][j] = temp[j] - '0';
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int input1, input2;
		cin >> input1 >> input2;
		vec.push_back(make_pair(input1, input2));
	}
	cout << solve();
	return 0;
}