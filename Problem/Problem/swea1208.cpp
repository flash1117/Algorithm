#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dumpCnt, maxHeight;
int map[100];
void init() {

	dumpCnt = 0;
	maxHeight = 0;
}


void solve() {

	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < 50; i++) {

		pq.push(map[99 - i] - map[i]);

	}

	for (int i = 0; i < pq.size(); i++) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return;
}




int main() {

	int t = 10;
	while (t--) {

		init();
		cin >> dumpCnt;
		for (int i = 0; i < 100; i++) {
			cin >> map[i];
		}

		sort(map, map + 100);
		solve();

		cout << "#" << 10 - t << " "<< maxHeight << "\n";
	}


	return 0;
}