#include <iostream>

using namespace std;

int L, N;
int map[1001];

int main() {

	pair<int, int> p1 = { 0,0 };
	pair<int, int> p2 = { 0,0 };

	int src, dst, maxCnt =0, temp=0;
	cin >> L;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		cin >> src >> dst;
		if (dst - src > p1.first) {
			p1.first = dst - src;
			p1.second = i;
		}

		for (int j = src; j <= dst; j++) {
			
			if (map[j] == 0) {
				map[j] = i;
				cnt++;
			}
		}
		if (cnt > p2.first) {
			p2.first = cnt;
			p2.second = i;
		}
	}
	cout << p1.second << "\n";
	cout << p2.second << "\n";

	return 0;
}