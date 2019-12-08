#include <iostream>
#include <cmath>

using namespace std;

pair <int, int> src, dst;

int map[10001][10001];

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>10000 || y>10000) return false;
	return true;
}

void solve() {

	
	int value = 1;
	pair <int, int> start = { 0,0 };

	if (src.first <= 0) {

		if (src.second <= 0) {
			start.first += src.first;
			start.second += src.second;
		}
		else { // ¾ç¼ö
			start.first += src.first;
		}
	}
	else { // src.first > 0
		if (src.second > 0);
		else { // src.second <= 0
			start.second += src.second;
		}
	}

	for (int i = 1; i <= 10000; i++) {

		for (int j = 0; j < 4; j++) {
			map[start.first][start.second] = i;
		}

	}
}

int main() {

	cin >> src.first >> src.second >> dst.first >> dst.second;

	solve();

	return 0;
}