#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
int A, B, N, M;
bool visited[100001];

bool isBoundary(int x)
{
	if (x < 0 || x>100000) return false;
	return true;
}

int BFS() {

	queue <pair<int,int>> q;
	visited[N] = true;
	q.push(make_pair(N, 0));

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == M) return cnt;

			int next;
				next = cur - 1;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur + 1;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur - A;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur + A;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur + B;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur - B;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur * A;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				next = cur * B;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}

		}
	
}

int main() {

	cin >> A >> B >> N >> M;

	cout << BFS();

	return 0;
}