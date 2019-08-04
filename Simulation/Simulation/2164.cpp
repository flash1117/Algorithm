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

		if (cnt % 2 == 1) 
			q.pop();
		else {
			int cur = q.front();
			q.pop();
			q.push(cur);

		}

		if (q.size() == 1) {
			cout << q.front();
			return;
		}

		cnt++;
	}


}

int main() {

	cin >> N;
	BFS();

	return 0;
}