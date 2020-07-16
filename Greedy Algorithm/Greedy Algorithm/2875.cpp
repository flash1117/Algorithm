#include <iostream>

using namespace std;

using pii = pair<int, int>;

int mo[1010100];
int cnt(int N) {

	int ret = 0;
	for (int i = 1; i * i <= N; i++)
		ret += (mo[i] * (N / (i * i)));
	return ret;
}

int32_t main() {

	for (int i = 1; i <= 1000000; i++)
		mo[i] = 1;
	for (int i = 2; i * i <= 1000000; i++) {

		if (mo[i] == 1) {
			for (int j = i; j <= 1000000; j += i)
				mo[j] *= -i;
			for (int j = i * i; j <= 1000000; j += i * i)
				mo[j] = 0;
		}

	}
	for (int i = 2; i <= 1000000; i++) {

		if (mo[i] == i) mo[i] = 1;
		else if (mo[i] == -i) mo[i] = -1;
		else if (mo[i] < 0) mo[i] = 1;
		else if (mo[i] > 0) mo[i] = -1;

	}

	int input;
	cin >> input;
	int lo = 0, hi = 1e12;
	while (lo + 1 < hi) {

		int mid = (lo + hi) / 2;
		if (cnt(mid) < input) lo = mid;
		else hi = mid;

	}
	cout << hi << "\n";	
	return 0;
}