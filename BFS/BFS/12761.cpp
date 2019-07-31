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

		for (int i = 0; i < 8; i++) {
			int next;
			switch (i)
			{
			case 0: {
				next = cur - 1;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			case 1:
			{
				next = cur + 1;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			case 2:
			{
				next = cur - A;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;

			}
			case 3: {
				next = cur + A;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			case 4:
			{
				next = cur + B;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			case 5: {
				next = cur - B;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			case 6: {
				next = cur * A;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			case 7: {
				next = cur * B;
				if (isBoundary(next) && !visited[next]) {
					q.push(make_pair(next, cnt + 1));
					visited[next] = true;
				}
				break;
			}
			default:
				break;
			}

		}
	}
}

int main() {

	cin >> A >> B >> N >> M;

	cout << BFS();

	return 0;
}