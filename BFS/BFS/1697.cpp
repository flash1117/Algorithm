#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100001] = { 0, };

queue <int> q;

int BFS() {

	q.push(N);
	visited[N] = true;

	while (!q.empty()) {

		int p = q.front(); q.pop();
		if (p == K) return visited[p] - 1;

		if (p - 1 >= 0 && visited[p - 1] == 0) {

			visited[p - 1] = visited[p] + 1;
			q.push(p - 1);

		}
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);

		}
		if (2 * p <= 100000 && visited[2 * p] == 0) {
			visited[2 * p] = visited[p] + 1;
			q.push(2 * p);

		}

	}

}
int main() {

	cin >> N >> K;
	cout << BFS();

}