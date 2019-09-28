#include <iostream>
#include <queue>

using namespace std;

int N;
int map[20001];

int findMaxDis(int input) {

	queue <pair<int, int>> q;
	q.push({ input, 0 });

	while (!q.empty()) {

		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (map[cur] == 1)
			return cnt;

		if (cur == input) {

			if (cur - 1 < 0 || cur + 1 > N);
			else {
				q.push({ cur - 1, cnt + 1 });
				q.push({ cur + 1, cnt + 1 });
			}
		}
		else if (cur < input) {
			if (cur - 1 < 0);
			else q.push({ cur - 1, cnt + 1 });
		}
		else {
			if (cur + 1 > N);
			else q.push({ cur + 1,cnt + 1 });
		}


	}

	return -1;
}

int main(void) {

	int input, ret = 0, buf = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> input;
		map[i] = input;
	}

	for (int i = 1; i <= N; i++) {

		if (map[i] == 0) buf = findMaxDis(i);
		if (buf > ret) ret = buf;
	}

	cout << ret;
	return 0;
}