#include <iostream>
#include <queue>

using namespace std;

int A, B, N, M;

int visited[100001];

bool isBoundary(int x) {
	if (x < 0 || x> 100000) return false;
	return true;
}

int solve() {
	int dx[] = { -1,1,A,B ,-A,-B };
	// A, B ´Â ½ºÄ«ÀÌ ÄáÄáÀÇ Èû
	queue <pair<int, int>> q;
	q.push({ N,1 }); // start , count
	visited[N] = 1;
	int ret = 200000;
	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

	//	cout << cur << " " << cnt << endl;

		if (cur == M) {
			ret = ret > cnt ? cnt : ret;
		}
		else {

			for (int i = 0; i < 6; i++) {
				int ccur = cur + dx[i];
			//	cout << cur << " " << dx[i] << endl;
				if (isBoundary(ccur) && (visited[ccur] == 0 || cnt + 1 < visited[ccur])) {
					q.push(make_pair(ccur, cnt + 1));
					visited[ccur] = cnt + 1;
				}

			}

			if (isBoundary(cur * A) && (visited[cur * A] == 0|| visited[cur * A] > cnt + 1)) {
				q.push(make_pair(cur * A, cnt + 1));
				visited[cur * A] = cnt + 1;
			}
			if (isBoundary(cur * B) && (visited[cur * B] == 0 || visited[cur * B] > cnt + 1)) {
				q.push(make_pair(cur * B, cnt + 1));
				visited[cur * B] = cnt + 1;
			}
			
		}

	}

	return ret-1;

}
int main() {

	cin >> A >> B >> N >> M;
	cout << solve() << "\n";


	return 0;
}