#include <iostream>

using namespace std;

int N, m, M, T, R;

int solve() {
	int time = 0;
	int cur = m;
	while (1) {

		if (m + T > M) break;

		if (N == 0) return time;

		if (cur + T <= M) {
			cur += T;
			N--;
			time++;
		}
		else { // 운동 못할때
			cur -= R;
			cur = m > cur ? m : cur;
			time++;
		}
	}

	return -1;
}

int main() {

	cin >> N >> m >> M >> T >> R;

	cout << solve() << "\n";
	return 0;
}