#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int paper1, paper2, paper3, paper4, paper5;
}Paper;

int map[10][10];
bool visited[10][10];
vector <pair<int, int>> pPos;
int minPaperCnt = 26;

bool isBoundary(int x, int y) {

	if (x < 0 || y < 0 || x>9 || y>9) return false;
	return true;

}

int getMaxSquare(int x, int y) {

	int ret = 1;

	for (int k = 1; k < 5; k++) {
		bool state = true;
		if (isBoundary(x + k, y + k)) {

			
			for (int i = x; i <= x + k; i++) {
				for (int j = y; j <= y + k; j++) {

					if (map[i][j] == 0) {
						state = false;
						break;
					}
					else if (visited[i][j]) {
						state = false;
						break;
					}
				}
			}

			
		}
		else break;

		if (state) ret = k + 1;
	}

	return ret;
}

void print() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void solve(int depth, int cnt, Paper paperCnt ) {

	if (depth == pPos.size()) {

		/*
		for (int i = 0; i < pPos.size(); i++) {
			if(!visited[pPos[i].first][pPos[i].second]) return;
		}
		
		*/
		
		

		minPaperCnt = minPaperCnt > cnt ? cnt : minPaperCnt;
		return;
	}

	int curX = pPos[depth].first;
	int curY = pPos[depth].second;

	if (visited[curX][curY]) {
		solve(depth + 1, cnt, paperCnt);
	}
	else {
		// bool _visited[10][10];

		/*
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				_visited[i][j] = visited[i][j];
			}
		}
		*/
		
		int maxSqaure = getMaxSquare(curX, curY);

		for (int i = 1; i <= maxSqaure; i++) {

			//cout << "curX : " << curX << " curY : " << curY << endl;
			//cout << "cur index : " << i << " maxSq : " << maxSqaure << endl;
			
			//print();

			if (i == 1 && paperCnt.paper1 > 0) {

				visited[curX][curY] = true;
				paperCnt.paper1--;
				solve(depth + 1, cnt + 1, paperCnt);
				paperCnt.paper1++;
				visited[curX][curY] = false;
			}
			else if (i == 2 && paperCnt.paper2 > 0) {

				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = true;
					}
				}

				paperCnt.paper2--;
				solve(depth + 1, cnt + 1, paperCnt);
				paperCnt.paper2++;
				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = false;
					}
				}

			}
			else if (i == 3 && paperCnt.paper3 > 0) {

				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = true;
					}
				}

				paperCnt.paper3--;
				solve(depth + 1, cnt + 1, paperCnt);
				paperCnt.paper3++;
				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = false;
					}
				}

			}
			else if (i == 4 && paperCnt.paper4 > 0) {

				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = true;
					}
				}

				paperCnt.paper4--;
				solve(depth + 1, cnt + 1, paperCnt);
				paperCnt.paper4++;
				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = false;
					}
				}

			}
			else if (i == 5 && paperCnt.paper5 > 0) {

				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = true;
					}
				}

				paperCnt.paper5--;
				solve(depth + 1, cnt + 1, paperCnt);
				paperCnt.paper5++;
				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i; k++) {
						visited[curX + j][curY + k] = false;
					}
				}

			}
			//solve(depth + 1, cnt, paperCnt);

		}

	}


	return;
}


int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			cin >> map[i][j];
			if (map[i][j] == 1) pPos.push_back(make_pair(i, j));
		}
	}


	solve(0, 0, { 5,5,5,5,5 });

	if (pPos.empty()) cout << 0 << "\n";
	else if (minPaperCnt == 26) cout << -1 << "\n";
	else cout << minPaperCnt << "\n";

	return 0;
}