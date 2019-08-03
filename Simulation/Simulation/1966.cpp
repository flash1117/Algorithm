#include <iostream>
#include <queue>

using namespace std;

int N, M;

int main() {

	int T, input;
	pair<int,int> dst;
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> N >> M;

		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++) {
			cin >> input;
			if (i == M) {
				dst.first = input;
				dst.second = i;
			}
			q.push(make_pair(input, i));
		}

		while (!q.empty()) {

			int cur = q.front().first;
			int index = q.front().second;
			q.pop();
		
			if (cur == dst.first && index == dst.second)
			{
				cout << cnt << endl;
				break;
			}

		
		}



	}

	return 0;
}