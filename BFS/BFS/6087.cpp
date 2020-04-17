#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {

	int x, y, dir;
}laser;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int visited[101][101];
int w, h;
char map[101][101];
vector <pair<int,int>> pos;

bool isBoundary(int x, int y) {

	if (x<0 || x>w || y<0 || y>h) return false;
	return true;
}

int solve() {

	queue <laser> q;
	q.push({pos[0].first, pos[0].second, 0});

	while (!q.empty()) {


	}



	return -1;
}


int main() {
	cin >> w >> h;
	string input;
	for (int i = 0; i < h; i++) {
		cin >> input;
		for (int j = 0; j < w; j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'C') pos.push_back(make_pair(i, j));
		}
	}
	

	return 0;
}