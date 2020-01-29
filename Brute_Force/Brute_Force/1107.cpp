#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ret = 500001;
int channel = 100;
vector <int> num = { 0,1,2,3,4,5,6,7,8,9 };
int pick[7];

void solve(int nLength , int depth , int cnt) {

	if (depth > num.size()) return;
	else if (cnt == nLength) {
		int sum = 0;
		int digit = 1;
		for (int i = cnt - 1; i >= 0; i--) {
			sum += digit * num[pick[i]];
			digit *= 10;
		}
		
		if (sum > N) ret = ret > (sum - N + nLength) ? (sum - N + nLength) : ret;
		else if (sum == N) ret = nLength;
		else  ret = ret > (N -sum + nLength) ? (N - sum + nLength) : ret;

		return;
	}

	pick[cnt] = depth;
	solve(nLength, depth + 1, cnt + 1);

	solve(nLength, depth + 1, cnt + 1);

	return;
}

int getNLen() {
	int cnt = 0;
	int temp = N;
	while (temp) {
		temp /= 10;
		cnt++;
	}
	return cnt;
}
int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		num[input] = 9;
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < M; i++)
		num.pop_back();

	if (N == 100) cout << 0 << "\n";
	else {
		solve(getNLen(), 0, 0);
		cout << ret << "\n";
	}

	return 0;
}