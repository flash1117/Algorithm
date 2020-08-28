#include <iostream>

using namespace std;


// n x n 체스판 위에 n개의 Queen이 서로 공격할 수 없도록 하는 문제.

int n, answer;
bool map[16][16];


bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return false;
	return true;
}


bool isValid(int x, int y) {

	if (map[x][y]) return false;

	for (int i = 0; i < n; i++) {
		if (map[i][y] || map[x][i]) return false;
	}

	for (int i = 1; i < n; i++) {

		if (isBoundary(x - i, y - i) && !map[x - i][y - i]);
		else if (!isBoundary(x - i, y - i)) break;
		else return false;
	}

	for (int i = 1; i < n; i++) {

		if (isBoundary(x + i, y + i) && !map[x + i][y + i]);
		else if (!isBoundary(x + i, y + i)) break;
		else return false;
	}
	
	for (int i = 1; i < n; i++) {

		if (isBoundary(x - i, y + i) && !map[x - i][y + i]);
		else if (!isBoundary(x - i, y + i)) break;
		else return false;
	}

	for (int i = 1; i < n; i++) {

		if (isBoundary(x + i, y - i) && !map[x + i][y - i]);
		else if (!isBoundary(x + i, y - i)) break;
		else return false;
	}

	return true;
}

void nQueen(int cnt) {

	if (cnt == 0) {
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {

		if (isValid(i, cnt - 1)) {
			map[i][cnt - 1] = true;
			nQueen(cnt - 1);
			map[i][cnt - 1] = false;
		}
		
	}

	return;
}



int main() {

	cin >> n;
	nQueen(n);

	cout << answer << "\n";
	return 0;
}