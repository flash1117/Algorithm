#include <iostream>
#include <queue>
using namespace std;

bool state = true;
int N, L, R;
int map[50][50];
bool visited[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

bool canMove(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		int dif = map[x][y] - map[nextX][nextY];
		dif = dif > 0 ? dif : -dif;

		if (isBoundary(nextX, nextY) && dif >= L && dif <= R) return true;
	}

	return false;
}

void print() {

	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	
}

void initArray() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void BFS(int x, int y) {

	queue <pair<int, int>> q;
	queue <pair<int, int>> country;
	int sum = 0;

	q.push({ x,y });
	visited[x][y] = true;

	while(!q.empty()){
		int curX = q.front().first;
		int curY = q.front().second;

		country.push(q.front());
		sum += map[curX][curY];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			int dif = map[curX][curY] - map[nextX][nextY];
			dif = dif > 0 ? dif : -dif;

			if (isBoundary(nextX, nextY) && dif >= L && dif <= R && !visited[nextX][nextY]) {

				q.push({ nextX, nextY });
				visited[nextX][nextY] = true;
			}
		}
	
	}

	if (country.size() == 1) {
		country.pop();
	}
	else {
		state = true;
		int peopleCnt = sum / country.size();
		int Size = country.size();
		for (int i = 0; i < Size; i++) {
			map[country.front().first][country.front().second] = peopleCnt;
			country.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int ret = 0;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	while (state) {

		state = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (canMove(i, j) && !visited[i][j]) {
					BFS(i, j);	
				}

			}
		}
		ret++;
		initArray();
	}

	cout << ret-1 << "\n";
	return 0;
}