#include <iostream>

using namespace std;

int N, M;

void solve() {

	int ret = 0;
	if (N > M) N -= M;

	for (int i = N; i > 0; i--) {
		if (M % i == 0) {
			ret += M / i - 1;
		}
	}

	return;
}

int main() {

	cin >> N >> M;


	return 0;
}