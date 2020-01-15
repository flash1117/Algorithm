#include <iostream>
#include <vector>

using namespace std;

typedef struct {

	int r, c, s, d, z; // x, y, 속력, 이동방향, 크기
}shark;

int map[101][101];
int R, C, M;
vector<shark> sh[10001];

void print() {
	cout << endl;
	for (int i = 1; i <= R; i++) {

		for (int j = 1; j <= C; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}


}

int getShark(int people_index) {
	int sharkSize = 0;

	for (int i = 1; i <= R; i++) {

		if (map[i][people_index] != 0) {
			sharkSize = sh[map[i][people_index]][0].z;
			sh[map[i][people_index]].pop_back();
			map[i][people_index] = 0;
			break;
		}
	}
	return sharkSize;
}

int chgDir(int currentDir) {

	if (currentDir == 0) return 1;
	else if (currentDir == 1) return 0;
	else if (currentDir == 2) return 3;
	else if (currentDir == 3) return 2;
}

shark chgPos(shark temp) {
	map[temp.r][temp.c] = 0;

	if (temp.d == 0) { // 위쪽
		int temp_s = temp.s % (2*(R-1));

		if (temp_s < temp.r) temp.r -= temp_s;
		else {
			temp_s -= temp.r - 1;

			if (temp_s > R - 1) {
				temp_s -= R - 1;
				temp.r = R - temp_s;
			}
			else {
				temp.r = 1 + temp_s;
				temp.d = chgDir(temp.d);
			}
			
		}
	}
	else if (temp.d == 1) { // 아래
		int temp_s = temp.s % (2 * (R - 1));

		if (temp_s <= R - temp.r) temp.r += temp_s;
		else {

			temp_s -= R - temp.r;

			if (temp_s > R - 1) {
				temp_s -= R - 1;
				temp.r = 1 + temp_s;
			}
			else {
				temp.r = R - temp_s;
				temp.d = chgDir(temp.d);
			}
			
		}
	}
	else if (temp.d == 2) { // 오른쪽

		int temp_s = temp.s % (2 * (C - 1));
		if (temp.s <= C - temp.c) temp.c += temp.s;
		else {

			temp_s -= C - temp.c;
			if (temp_s > C - 1) {
				temp_s -= C - 1;
				temp.c = 1 + temp_s;
			}
			else {
				temp.c = C - temp_s;
				temp.d = chgDir(temp.d);
			}
		
		}
	}
	else { // currentDir = 3 , 왼쪽
		int temp_s = temp.s % (2 * (C - 1));

		if (temp.s < temp.c) temp.c -= temp.s;
		else {
			temp_s -= temp.c - 1;
			if (temp_s > C - 1) {
				temp_s -= C - 1;
				temp.c = C - temp_s;
			}
			else {
				temp.c = 1 + temp_s;
				temp.d = chgDir(temp.d);
			}
		}
	}

	return temp;
}

int solve() {

	int ret = 0;
	for (int i = 1; i <= C; i++) {

		ret += getShark(i);
		for (int j = 1; j <= M; j++) {

			if (!sh[j].empty()) {
				sh[j][0] = chgPos(sh[j][0]);
			}
		}
		print();
		for (int j = 1; j <= M; j++) {
			if (!sh[j].empty()) {
				if (map[sh[j][0].r][sh[j][0].c] != 0) {
					if (sh[map[sh[j][0].r][sh[j][0].c]][0].z > sh[j][0].z) {
						sh[j].pop_back();
					}
					else {
						
						sh[map[sh[j][0].r][sh[j][0].c]].pop_back();
						map[sh[j][0].r][sh[j][0].c] = j;
					}
				}
				else {
					map[sh[j][0].r][sh[j][0].c] = j;
				}
			}
		}

	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	shark input;
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> input.r >> input.c >> input.s >> input.d >> input.z;
		input.d--;
		sh[i].push_back(input);
		map[input.r][input.c] = i;
	}

	cout << solve() << "\n";

	return 0;
}