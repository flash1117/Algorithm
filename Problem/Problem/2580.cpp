#include <iostream>
#include <vector>

using namespace std;

int map[9][9];
vector<pair<int, int>> zeroPos;
int zeroCnt;
bool visited[9][9];
bool isPrint;
bool lineCheck(int x, int y, int goal_num) {

	
	for (int i = 0; i < 9; i++) {

		if (map[x][i] == goal_num || map[i][y] == goal_num) return false;
	}

	return true;
}


bool squareCheck(int x, int y, int goal_num) {

	for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++) {

		for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
		{
			if (map[i][j] == goal_num) return false;
		}
	}
	

	return true;
}

/*
bool isAllVisited() {

	for (int i = 0; i < zeroPos.size(); i++) {
		if (!visited[zeroPos[i].first][zeroPos[i].second]) return false;
	}
	return true;
}

*/

void print() {
	//cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	
	return;
}

void solve(int depth ,int cnt) {

	
	if (cnt == zeroCnt && !isPrint) {

		print();
		isPrint = true;
		return;
	}
	if (depth > zeroPos.size()) return;

		int x = zeroPos[depth].first;
		int y = zeroPos[depth].second;

		if (map[x][y] > 0) return;

		for (int k = 1; k <= 9; k++) {

			if (lineCheck(x, y, k) && squareCheck(x, y, k)) {
				map[x][y] = k;
				solve(depth+1, cnt + 1);
				map[x][y] = 0;
			}
		}

	
	/*
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] != 0) continue;
			else {
				for (int k = 1; k <= 9; k++) {
					
					if (lineCheck(i, j, k) && squareCheck(i, j, k)) {
						map[i][j] = k;
						solve(cnt + 1);
						map[i][j] = 0;
					}
				}

			}
		}
	}
	*/
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zeroPos.push_back(make_pair(i, j));
				zeroCnt++;
			}
		}
	}

	solve(0,0);

	return 0;
}