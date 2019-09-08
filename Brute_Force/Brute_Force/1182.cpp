#include <iostream>

using namespace std;

#define MAXNUM 21

int N, S;
int num[MAXNUM];
int ans;

void solve(int i , int prevSum) {

	if (i == N) {

		if (prevSum == S)
			ans++;
		return;
	}

	solve(i + 1, prevSum + num[i]);
	solve(i + 1, prevSum);
}

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	solve(0,0);

	if (S == 0) ans -= 1;
	cout << ans;

	return 0;
}

