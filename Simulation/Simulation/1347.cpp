#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[120][120];
string input;

typedef struct {
	int x, y, dir;
}pos;

int chgDir(int cur, char ch) {

	if (ch == 'L') {
		if (cur == 0) return 3;
		else return cur - 1;
	}
	else if(ch == 'R') {
		if (cur == 3) return 0;
		else return cur + 1;
	}
	
}

void solve() {

	queue <pos> q;
	q.push({ 60,60,2 });
	int index = 0;
	int maxX = 60, minX = 60, maxY = 60, minY = 60;

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int dir = q.front().dir;
		map[curX][curY] = 1;

		q.pop();

		maxX = curX > maxX ? curX : maxX;
		maxY = curY > maxY ? curY : maxY;
		minX = curX > minX ? minX : curX;
		minY = curY > minY ? minY : curY;

		if (index == input.length()) break;
		if (input[index] == 'F') {
			q.push({ curX + dx[dir], curY + dy[dir], dir });
		}
		else {
			dir = chgDir(dir, input[index]);
			q.push({ curX, curY, dir });
		}
		index++;

	}

	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			if (map[i][j] != 0) cout << ".";
			else cout << "#";
		}
		cout << "\n";
	}

}

int main() {

	int N;
	cin >> N;
	cin >> input;
	solve();

	return 0;
}