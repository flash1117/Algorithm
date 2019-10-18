#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int N, M;
queue <int> pos;

int retDir(deque <int>& dq) {
	int right = 0, left = 0;
	int dqSize = dq.size();
	for (int i = 0; i < dqSize; i++) {

		if (pos.front() == dq[i]) {
			left = i - 0;
			right = dq.size() - 1 - i;
			if (left > right) return 1; // right
			else if (right >= left) return 0; // left
		}
	}
	return -1;
}

int solve() {
	deque <int> dq;
	int dir = -1, sum = 0, move = 0;
	
	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	while (!pos.empty()) {

		move = 0;
		int dqSize = dq.size();
		dir = retDir(dq);

		if (dir == 0) {
			for (int i = 0; i <= dqSize; i++) {

				int cur = dq.front();
				dq.pop_front();

				if (cur == pos.front()) {
					pos.pop();
					sum += move;
					break;
				}
				
				move++;
				dq.push_back(cur);
				
			}
		}
		else if (dir == 1) {

			for (int i = 0; i <= dqSize; i++) {

				int cur = dq.back();
				dq.pop_back();
				if (cur == pos.front()) {
					pos.pop();
					sum += move + 1;
					break;
				}
				move++;
				dq.push_front(cur);
				
			}
		}
		
	}
	return sum;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		pos.push(temp);

	}
		
	cout <<solve();

	return 0;
}