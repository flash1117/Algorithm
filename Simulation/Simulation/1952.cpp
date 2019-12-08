#include <iostream>
#include <queue>

using namespace std;

int M, N;
bool visited[101][101];

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>M - 1 || y>N - 1) return false;
	return true;
}

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int chgDir(int curDir) {

	if (curDir != 3) return curDir + 1;
	else return 0;

}

int solve() {

	int cnt = 0, dir = 0;
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		
		q.pop();

		int nextX = curX + dx[dir];
		int nextY = curY + dy[dir];

		if (isBoundary(nextX, nextY) && !visited[nextX][nextY])
		{
			q.push(make_pair(nextX, nextY));
			visited[nextX][nextY] = true;
		}
		else {
			
				q.push(make_pair(curX, curY));
				dir = chgDir(dir);
				if (visited[curX + dx[dir]][curY + dy[dir]]) return cnt;
				cnt++;
			
		}
	}
	return cnt;
}

int main() {
	cin >> M >> N;

	cout << solve() << "\n";

	return 0;
}