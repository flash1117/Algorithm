#include <iostream>
using namespace std;

struct pos {
	int y, x;
};

int n;
double dir[4], res;
bool visited[31][31];
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { -1, 1, 0, 0 };

void dfs(int y, int x, int depth, double percentage) {
	if (depth == n) {
		res += percentage;
		return;
	}

	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!visited[ny][nx]) {
			dfs(ny, nx, depth + 1, percentage * dir[i]);
		}
	}
	visited[y][x] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 4; ++i) {
		cin >> dir[i];
		dir[i] /= 100;
	}
	dfs(15, 15, 0, 1.0);
	cout << fixed;
	cout.precision(10);
	cout << res << endl;
	return 0;
}