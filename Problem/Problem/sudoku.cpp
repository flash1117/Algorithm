#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int x, y, value;
}pos;

int map[9][9];
int numbers[10];
bool visited[10];
vector <int> incorrect;
vector <pos> ret;

void initArray() {
	for (int i = 1; i < 10; i++)
		numbers[i] = 0;
}

bool isCorrectNum(int row, int col) {
	for (int i = 0; i < 9; i++) {
		visited[map[row][i]] = true;
	}

	for (int i = 1; i <= 9; i++) {
		if (!visited[i]) return false;
		visited[i] = false;
	}

	for (int i = 0; i < 9; i++) {
		visited[map[i][col]] = true;
	}

	for (int i = 1; i <= 9; i++) {
		if (!visited[i]) return false;
		visited[i] = false;
	}

	return true;
}

bool sq_check(int row, int col) {

	for (int i = row; i < row + 3; i++)
		for (int j = col; j < col + 3; j++)
			numbers[map[i][j]]++;

	for (int i = 1; i <= 9; i++) {
		if (numbers[i] == 0) incorrect.push_back(i);
	}

	if (incorrect.empty()) return true;
	else return false;

}


void solve() {

	for (int si = 0; si < 9; si += 3) {
		for (int sj = 0; sj < 9; sj += 3) {
			if (!sq_check(si, sj)) {

				for (int i = si; i < si + 3; i++) {

					for (int j = sj; j < sj + 3; j++) {
						if (numbers[map[i][j]] > 1) {

							for (int k = 0; k < incorrect.size(); k++) {
								int tmp = map[i][j];
								map[i][j] = incorrect[k];
								if (isCorrectNum(i, j)) {
									ret.push_back({ i + 1, j + 1, incorrect[k] });
									break;
								}
								else map[i][j] = tmp;
							}
						}
					}
				}

			}
			incorrect.clear();
			initArray();
		}
	}


}

int main() {

	int T, N, caseNum = 1;
	cin >> T;
	while (T--) {

		cin >> N;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
			{
				cin >> map[i][j];
			}
		}

		solve();
		cout << "#" << caseNum++ << " ";
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i].x << " " << ret[i].y << " " << ret[i].value << " ";
		}
		cout << "\n";
		ret.clear();
	}
	return 0;
}