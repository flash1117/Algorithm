#include <iostream>
#include <vector>

using namespace std;

int N, M;
int pick[7];
vector <int> vec;

void solve(int depth, int cnt) {

	if (depth > N) return;
	else if (cnt == M) {

		for (int i = 0; i < M; i++) {
			cout << pick[i] << " ";
		}
		cout << "\n";
		return;
	}


	for (int i = depth; i < N; i++) {

		if (depth < vec.size()) {
			pick[cnt] = vec[depth];
			solve(depth + 1, cnt + 1);
			solve(depth + 1, cnt);
		}
	}
	
	return;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		vec.push_back(i + 1);

	solve(0, 0);

	return 0;
}