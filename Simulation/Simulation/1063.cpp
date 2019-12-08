#include <iostream>
#include <vector>

using namespace std;

int K, S, N;
int map[8][8];
pair<int, int> king, stone;

vector <string> vec;

int dx[] = { 0,0,1,-1,-1,-1,1,1 }; // R L B T RT LT RB LB
int dy[] = { 1,-1,0,0,1,-1,1,-1 };

bool isBoundary(int x, int y) {

	if (x < 0 || y < 0 || x>7 || y>7) return false;
	return true;
}

int moveDir(string move) {

	if (move == "R") return 0;
	else if (move == "L") return 1;
	else if (move == "B") return 2;
	else if (move == "T") return 3;
	else if (move == "RT") return 4;
	else if (move == "LT") return 5;
	else if (move == "RB") return 6;
	else if (move == "LB") return 7;
}

void matchMap(string input1, string input2) {

	king.first = input1[0] - 'A';
	king.second = 8-(input1[1] - '0');
	
	stone.first = input2[0] - 'A';
	stone.second = 8-(input2[1] - '0');
}

void solve() {
	int kingX = king.second;
	int kingY = king.first;

	int stoneX = stone.second;
	int stoneY = stone.first;

	for (int i = 0; i < vec.size(); i++) {

		int dir = moveDir(vec[i]);
		int nextX = kingX + dx[dir];
		int nextY = kingY + dy[dir];

		if (isBoundary(nextX, nextY)) {
			int snextX = stoneX + dx[dir];
			int snextY = stoneY + dy[dir];

			if (nextX == stoneX && nextY == stoneY) {
				if (isBoundary(snextX, snextY)) {
					kingX = nextX;
					kingY = nextY;
					stoneX = snextX;
					stoneY = snextY;
				}
			}
			else {
				kingX = nextX;
				kingY = nextY;
			}

		}
	}

	char retX = kingY + 'A';
	char retY = 8 - kingX + '0';

	char sretX = stoneY + 'A';
	char sretY = 8 - stoneX + '0';

	cout << retX << retY << "\n";
	cout << sretX << sretY << "\n";

}

int main() {

	string input1, input2;
	cin >> input1 >> input2 >> N;
	matchMap(input1, input2);
	for (int i = 0; i < N; i++) {
		cin >> input1;
		vec.push_back(input1);
	}
	solve();
	return 0;
}