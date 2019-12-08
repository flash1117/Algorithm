#include <iostream>
#include <queue>

using namespace std;

int N, M, L;
int cntArray[1001];

bool isBoundary(int x)
{
	if (x<1 || x>N) return false;
	return true;
}

int solve() {

	cntArray[1] = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(1, 0));

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cntArray[cur] == M) return cnt;

		int next = 0;

		if (cntArray[cur] % 2 == 1) { // È¦¼ö -> ½Ã°è

			next = cur + L;
			if (!isBoundary(next)) 
				next -= N;
			q.push(make_pair(next, cnt + 1));
			cntArray[next]++;
		}
		else { // Â¦¼ö -> ¹Ý½Ã°è

			next = cur - L;
			if (!isBoundary(next)) next += N;
			q.push(make_pair(next, cnt + 1));
			cntArray[next]++;
		}

	}

	return -1;
}

int main() {

	cin >> N >> M >> L;
	cout << solve() << "\n";

	return 0;
}