#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int x, y, d1, d2;
}Bound;

int N, ret = 40001, peopleCnt;
int map[21][21];
vector <Bound> Area;

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

bool setBound(Bound input) {

	if (!isBoundary(input.x + input.d1, input.y - input.d1)) return false;
	else if (!isBoundary(input.x + input.d2, input.y + input.d2)) return false;

	return true;
}

void solve() {
	for (int k = 0; k<Area.size(); k++) {
		int pNum[5] = { 0,0,0,0,0 };
		for (int i = 0; i < Area[k].x + Area[k].d1 - 1; i++) { // area 1
			for (int j = 0; j < Area[k].y; j++) {
				pNum[0] += map[i][j];
			}
		}
		if (pNum[0] == 0) continue;

		for (int i = 0; i < Area[k].x + Area[k].d1 - 1; i++) { // area 2
			for (int j = Area[k].y; j < N; j++) {
				pNum[1] += map[i][j];
			}
		}
		if (pNum[1] == 0) continue;

		for (int i = Area[k].x + Area[k].d1 - 1; i < N; i++) {
			for (int j = 0; j < Area[k].y; j++) {
				pNum[2] += map[i][j];
			}
		}
		if (pNum[2] == 0) continue;

		for (int i = Area[k].x + Area[k].d1 - 1; i < N; i++) {
			for (int j = Area[k].y; j < N; j++) {
				pNum[3] += map[i][j];
			}
		}
		if (pNum[3] == 0) continue;

		pNum[4] = peopleCnt - pNum[0] - pNum[1] - pNum[2] - pNum[3];
		if (pNum[4] == 0) continue;
		sort(pNum, pNum+4);
		int dif = pNum[0] - pNum[4];
		ret = ret > dif ? dif : ret;
	}

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			peopleCnt += map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					Bound input = { i,j,d1,d2 };
					bool isBound = setBound(input);
					if (isBound) Area.push_back(input);
				}
			}
		}
	}
	solve();
	cout << ret << "\n";

	return 0;
}