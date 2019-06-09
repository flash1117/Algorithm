#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int M, N; // 2이상 1000이하
int map[1001][1001];
bool visited[1001][1001];


int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y;
}pt;

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>M - 1 || y>N - 1) return false;
	return true;
}

int BFS() {
	queue<pt> q;
	q.push({})


}



int main() {

	cin >> M >> N;
	cout << BFS();
	return 0;
}