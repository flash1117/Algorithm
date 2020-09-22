#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x, y, cnt;
}Pos;

int n, m;
int map[100][100];
bool visited[100][100];

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return false;;
	return true;
}


vector<pair<int, int>> getNextCheeseArray(vector<pair<int,int>> startIndex) {


	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	vector<pair<int, int>> ret;
	queue<pair<int,int>> q;

	for (int i = 0; i < startIndex.size(); i++) {

		q.push({ startIndex[i].first,startIndex[i].second });
	}
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] == 0 && !visited[nextX][nextY]) {
				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
			else if (isBoundary(nextX, nextY) && map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
				ret.push_back(make_pair(nextX, nextY));
				visited[nextX][nextY] = true;
			}

		}

	}

	return ret;
}

void meltCheese(vector<pair<int,int>> cheese) {

	for (int i = 0; i < cheese.size(); i++) {
		map[cheese[i].first][cheese[i].second] = 0;
	}
	return;
}

void print(vector<pair<int,int>> vec) {

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << " " << vec[i].second << endl;

	}
	cout << endl;
}

pair<int,int> solve() {

	vector<pair<int, int>> nextCheese;
	nextCheese.push_back({ 0,0 });
	int meltTime = 0, lastCheesePieceCnt=0;


	while (!nextCheese.empty()) {

		lastCheesePieceCnt = nextCheese.size();
		nextCheese = getNextCheeseArray(nextCheese);

		//print(nextCheese);

		if (nextCheese.empty()) break;
		else {

			meltTime++;
			meltCheese(nextCheese);

		}

	}

	if (meltTime == 0) lastCheesePieceCnt = 0;

	return make_pair(meltTime, lastCheesePieceCnt);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	pair<int,int> ret = solve();

	cout << ret.first << "\n";
	cout << ret.second << "\n";
	return 0;
}