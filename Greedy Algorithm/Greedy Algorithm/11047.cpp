#include <iostream>
#include <vector>

using namespace std;

int N, K, minCnt;
vector <int> coin;

void solve() {

	
	for (int i = N - 1; i >= 0; i--) {
		if (coin[i] > K);
		else {

			minCnt += K / coin[i];
			K = K % coin[i];
		}

	}

}

int main() {

	int input;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {

		cin >> input;
		coin.push_back(input);

	}
	solve();
	cout << minCnt;
	return 0;
}