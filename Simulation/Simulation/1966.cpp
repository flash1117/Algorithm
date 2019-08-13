#include <iostream>
#include <deque>

using namespace std;

int N, M;
deque <pair<int, int>> dq;

bool isMax(int a) {

	for (int i = 0; i < dq.size(); i++) 
		if (dq[i].first > a) return false;
	return true;
}

int main()
{
	
	int T, input, cnt=0;
	cin >> T;
	while (T--) {

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> input;
			dq.push_back(make_pair(input, i));
		}

		while(1) {
			if (isMax(dq[0].first)) {
				cnt++;
				if (dq.front().second == M) {
					cout << cnt << endl;
					break;
				}
				dq.pop_front();

			}
			else {
				pair<int, int> p;
				p = dq.front();
				dq.pop_front();
				dq.push_back(p);

			}

		}

		cnt = 0;
		dq.clear();
	}

	return 0;
}