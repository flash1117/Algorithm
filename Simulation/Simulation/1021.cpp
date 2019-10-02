#include <iostream>
#include <deque>
#include <vector>

using namespace std;

#define Endl "\n"

int N, M;
vector <int> element;
deque <int> dq;

void print() {

	for (int i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << Endl;

}

int solve() {
	int index = 0, cnt = 0, state = 0;
	

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	while (!dq.empty()) {

		print();
		if (index >= element.size()) return cnt;
		state = 0;
		int mid = dq.size() / 2;

		for (int i = 0; i < dq.size(); i++) { // 어느 쪽이 가까운지 비교

			if (element[index] == dq[i]) {

				if (i <= mid) state = 1;
				else state = 2;
				break;
			}
		}

		if (state == 1) {

			for (int i = 0; i < dq.size(); i++) {
				int cur = dq.front();
				dq.pop_front();

				if (cur == element[index]) {
					index++;
					break;
				}
				else dq.push_back(cur); cnt++;
			}

		}
		else if (state == 2) {
			for (int i = dq.size(); i > 0; i--) {
				int cur = dq.back();
				dq.pop_back();

				if (cur == element[index]) {
					index++;
					break;
				}
				else dq.push_front(cur); cnt++;
			}
		}

	}

	return cnt;
}

int main() {

	int temp = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		element.push_back(temp);
	}
		
	cout << solve();

	
	return 0;
}