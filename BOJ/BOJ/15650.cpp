#include <iostream>

using namespace std;

int N, M;
int pick[9], input[9];

void solve(int depth , int cnt) {

	if (depth > N) return;
	else if (cnt == M) {

		for (int i = 0; i < M; i++) {
			cout << pick[i] << " ";
		}
		cout << "\n";

		return;
	}

	pick[cnt] = input[depth];
	solve(depth + 1, cnt+1);
	solve(depth + 1, cnt);

	return;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		input[i] = i+1;
	solve(0,0);

	return 0;
}