#include <iostream>

using namespace std;

const int INF = 987654321;

int N, M, H;
int map[31][31];
int minCnt = INF;
void print() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int ladderClimb(int index) {

	for (int i = 1; i <= H; i++) {
		if (map[i][index] == 1) index++;
		else if (map[i][index] == -1) index--;
	}

	return index;
}


void setLadder(int index, int cnt) {
	if (cnt >= 4) return;
	//	print();
	bool isAnswer = true;
	for (int i = 1; i <= N; i++) {
		if (i == ladderClimb(i));
		else {
			isAnswer = false;
			break;
		}
	}
	if (isAnswer) {
		minCnt = minCnt > cnt ? cnt : minCnt;
		return;
	}


	for (int j = index; j <= H; j++) {
		for (int i = 1; i < N; i++) {

			if (map[j][i] == 0 && map[j][i + 1] == 0) {

				map[j][i] = 1;
				map[j][i + 1] = -1;
				setLadder(j, cnt + 1);
				map[j][i] = 0;
				map[j][i + 1] = 0;
			}

		}
	}



	return;
}


int main() {

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[x][y + 1] = -1;

	}


	setLadder(1, 0);

	if (minCnt == INF) {
		cout << -1 << "\n";
	}
	else cout << minCnt << "\n";



	return 0;
}