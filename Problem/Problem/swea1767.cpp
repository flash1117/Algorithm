#include <iostream>
#include <vector>
using namespace std;

int map[12][12];
int N, core, len;
vector<pair<int, int>> vec;
bool visited[12][12];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

bool isValid(pair<int,int> pos, int dir) {

	int curX = pos.first;
	int curY = pos.second;
	for (int i = 0; i < N+1; i++) {

		int nextX = curX + dx[dir];
		int nextY = curY + dy[dir];

		if (isBoundary(nextX, nextY) && map[nextX][nextY] == 1) return false;
		else if (isBoundary(nextX, nextY) && visited[nextX][nextY]) return false;
		else if(!isBoundary(nextX, nextY)){
			return true;
		}

		curX += dx[dir];
		curY += dy[dir];
	}

	return false;
}

int setValid(pair<int, int> pos, int dir) {

	int ret = 0;
	int curX = pos.first;
	int curY = pos.second;

	for (int i = 0; i < N+1; i++) {

		if (isBoundary(curX, curY)) {
			visited[curX][curY] = true;
			curX += dx[dir];
			curY += dy[dir];
			ret++;
		}
		else break;

	}
	return ret-1;
}

void solve(int depth ,int cnt, int sum) {

	if (cnt <= vec.size()) {

		cout << len << " ";

		if (core < cnt) {
			core = cnt;
			len = sum;
		}
		else if (core == cnt) {
			len = len > sum ? sum : len;
		}
	


	}

	if (depth >= vec.size()) return;

	for (int i = 0; i < 4; i++) {

		bool canBuild = isValid(vec[depth], i);
	//	cout << vec[depth].first << " " << vec[depth].second << " " << canBuild << endl;
		if (canBuild) {

			int _len = setValid(vec[depth], i);
			solve(depth + 1, cnt + 1, sum + _len);

			int curX = vec[depth].first;
			int curY = vec[depth].second;

			for (int j =0; j < N+1; j++) {

				if (isBoundary(curX, curY)) {
					visited[curX][curY] = false;
					curX += dx[i];
					curY += dy[i];
				}
				else break;

			}


		}

	}

	solve(depth + 1, cnt, sum);

	return;
}


int main() {


	int num = 0;
	int t;
	cin >> t;
	while (t--) {

		num++;
		core = 0;
		int _core = 0;
		len = 0;
		vec.clear();

		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = false;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				cin >> map[i][j];
				if (map[i][j]) {
					
					if (i == 0 || i == N - 1 || j == 0 || j == N - 1) _core++;
					else {
						vec.push_back(make_pair(i, j));
					}
				}
			}
		}

		solve(0,0,0);
		cout << "#"<<num <<" " <<len << "\n";
	}

	return 0;
}