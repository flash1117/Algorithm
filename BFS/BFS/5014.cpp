#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


int F, S, G, U, D;
bool visited[1000001];
int dx[2];

bool isBoundary(int x) {

	if (x<0 || x>F - 1) return false;
	return true;
}

int BFS() {

	queue <pair<int,int>> q;
	q.push({ S - 1 ,0 });
	visited[S-1] = true;

	dx[0] = U;
	dx[1] = D * (-1);
	
	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == G - 1)
			return cnt;

		for (int i = 0; i < 2; i++) {
			int next = cur + dx[i];

			if (isBoundary(next) && !visited[next]) {

				visited[next] = true;
				q.push({ next , cnt + 1 });
			}

		}
		
	}
	return -1;
}

int main() {

	cin >> F >> S >> G >> U >> D;

	int ret = BFS();
	if (ret == -1)
		cout << "use the stairs";
	else
		cout << ret;

	return 0;
}