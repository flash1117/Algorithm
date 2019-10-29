#include <iostream>

using namespace std;

int N, maxLen;
int input[1001];
int Ldp[1001], Rdp[1001];

void solve() {

	maxLen = Rdp[N] = Ldp[1] = 1;

	for (int i = 2; i <= N; i++) {

		for (int j = i - 1; j >= 0; j--) {

			if (input[i] > input[j])
				Ldp[i] = (Ldp[j] + 1 > Ldp[i]) ? Ldp[j] + 1 : Ldp[i];
		}
	}

	for (int i = N-1; i >= 1; i--) {

		for (int j = i + 1; j <= N+1; j++) {

			if (input[i] > input[j])
				Rdp[i] = (Rdp[j] + 1 > Rdp[i]) ? Rdp[j] + 1 : Rdp[i];
		}
	}

	for (int i = 1; i <= N; i++) 
		maxLen = (Ldp[i] + Rdp[i] > maxLen) ? Ldp[i] + Rdp[i] : maxLen;
	
	cout << maxLen - 1;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> input[i];

	solve();
	return 0;
}