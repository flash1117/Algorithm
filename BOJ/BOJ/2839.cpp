#include <iostream>

using namespace std;

int N;

int solve() {

	int maxNum = N / 5;
	int ret = 2000;

	for (int i = 0; i <= maxNum; i++) {

		if (N - 5 * i > 0) {
			if ((N - 5 * i) % 3 == 0) {
				int temp = (N - 5 * i) / 3 + i;
				ret = ret > temp ? temp : ret;
			}
		}
		else if (N == 5 * i) ret = ret > i ? i : ret;
		
	}

	if (ret == 2000) return -1;
	else return ret;
}

int main() {
	cin >> N;

	cout << solve() << "\n";
	return 0;
}