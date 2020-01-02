#include <iostream>

using namespace std;

int tNum[1001];
bool is_tNum[1001];

void solve() {

	for (int i = 1; i <= 1000; i++) 
		tNum[i] = i * (i + 1) / 2;
	
	for (int i = 1; i <= 1000; i++) {

		for (int j = 1; j <= 1000; j++) {

			int sum = tNum[i] + tNum[j];
			if (sum > 1000) break;

			for (int k = 1; k <= 1000; k++) {

				sum = tNum[i] + tNum[j] + tNum[k];
				if (sum > 1000) break;

				if (is_tNum[sum]) continue;
				else is_tNum[sum] = true;
			}
		}
	}

}


int main() {

	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	solve();

	while (T--) {

		int input;
		cin >> input;

		cout << is_tNum[input] << "\n";
	}


	return 0;
}