#include <iostream>

using namespace std;

int map[401][401];
int n, k, s;

void solve() {

	for (int mid = 1; mid <= n; mid++) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][mid] == 1 && map[mid][j] == 1)
					map[i][j] = 1, map[j][i] = -1;
			
			}
		}
	}

}

int main() {

	int input1, input2;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {

		cin >> input1 >> input2;
		map[input1][input2] = -1;
		map[input2][input1] = 1;

	}

	solve();
	cin >> s;
	for (int i = 0; i < s; i++) {

		cin >> input1 >> input2;
		cout << map[input1][input2] << endl;
	}


	return 0;
}