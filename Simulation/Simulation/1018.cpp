#include <iostream>
#include <algorithm>

using namespace std;

int N, M, cnt, minCnt = 65;
char map[51][51];
string chessW[8] = {

	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"}

};

string chessB[8] = {

	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"}

};


bool isBoundary(int x, int y) {

	if (x < 0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void solve(int x , int y) {

	int Black = 0, White = 0;
	if (!isBoundary(x + 7, y + 7)) return;

	for (int i = x; i < x + 8; i++) {

		for (int j = y; j < y + 8; j++) {
			if (map[i][j] != chessB[i-x][j-y])
				Black++;
			if (map[i][j] != chessW[i-x][j-y])
				White++;
		}

	}

	cnt = min(Black, White);
	minCnt = min(cnt, minCnt);

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
		
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			solve(i,j);

	cout << minCnt;
	return 0;
}