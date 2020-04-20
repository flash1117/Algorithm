#include <iostream>

using namespace std;

const int INF = 987654321;

int main() {

	int e, s, m;
	cin >> e >> s >> m; // 15 28 19 까지 범위

	for (int i = 0; i < INF; i++) {

		for (int j = 0; j <= i; j++) {

			for (int k = 0; k <= i; k++) {

				int E = e + 15 * i;
				int S = s + 28 * j;
				int M = m + 19 * k;
				if (E == S && S == M) {
					cout << E << "\n";
					return 0;
				}
			}
		}

	}

	return 0;
}