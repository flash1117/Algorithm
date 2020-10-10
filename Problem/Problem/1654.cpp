#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
long long maxLen;
vector<long long> pipe;

long long getCutting(int cutLen) {
	long long sum = 0;
	for (int i = 0; i < pipe.size(); i++) {

		sum += (pipe[i] / cutLen);

	}
	return sum;
}

void solve(long long start, long long end) {

	while (start <= end) {

		long long mid = (start + end) / 2;

		long long cnt = getCutting(mid);

		if (cnt >= N) {
			maxLen = maxLen > mid ? maxLen : mid;
			start = mid + 1;

		}
		else end = mid - 1;

	}

	return;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long input;
		cin >> input;
		pipe.push_back(input);
	}
	sort(pipe.begin(), pipe.end());

	solve(1, pipe.back());
	cout << maxLen << "\n";

	return 0;
}