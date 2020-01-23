#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector <long long> A, B, C, D;
int pick[10];

void solve(int depth, int cnt) {

	if (depth > N) return;
	else if (cnt == 4) {

		for (int i = 0; i < 4; i++)
			cout << pick[i] << " ";
		cout << endl;

		int sum = 0;
		sum = A[pick[0]] + B[pick[1]] + C[pick[2]] + D[pick[3]];
		if (sum == 0) ret++;
	}

	for (int i = 0; i < N; i++) {
		pick[cnt] = i;
		solve(depth + 1, cnt + 1);
	}
}

int main() {

	long long a, b, c, d;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		A.push_back(a); B.push_back(b); C.push_back(c); D.push_back(d);
	}

	solve(0, 0);
	cout << ret << "\n";
	return 0;
}