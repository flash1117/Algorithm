#include <iostream>
#include <queue>

using namespace std;

int N;

void BFS() {

	int cnt = 1;
	queue <int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (!q.empty()) {

		if (cnt % 2 == 1) {
			cout << q.front() << " ";
			q.pop();
		}
		else {
			int cur = q.front();
			q.pop();
			q.push(cur);
		}
		cnt++;
	}

}

int main() {

	cin >> N;
	BFS();

	return 0;
}