#include <iostream>
#include <vector>

using namespace std;

int n;
const int INF = 987654321;


bool isEnd(int num) {

	int cnt = 0;

	while (num) {

		int q = num % 10;

		if (q == 6) cnt++;
		else {
			cnt = 0;
		}

		if (cnt == 3) return true;

		num /= 10;
	}

	return false;
}

int main() {

	cin >> n;
	int ret = 0;
	for (int i = 666; i < INF; i++) {

		if (isEnd(i)) {
			ret++;
		}

		if (ret == n) {
			cout << i << "\n";
			break;
		}

	}

	return 0;
}