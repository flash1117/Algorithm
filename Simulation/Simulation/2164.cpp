#include <iostream>
#include <queue>

using namespace std;

int N;

void solve() {

	int cnt = 1;
	queue <int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (1) {
		if (q.size() == 1) {
			cout << q.front() << "\n";
			break;
		}
		else {
			int cur = q.front();
			q.pop();
			if (cnt % 2 == 1);
			else q.push(cur);
			cnt++;
		}
	}
	return;
}

int main() {

	cin >> N;
	solve();

	return 0;
}