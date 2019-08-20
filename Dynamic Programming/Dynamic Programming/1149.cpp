#include <iostream>

using namespace std;

int N;
int dp[1001];
int home[1001][3];
int sum;

void solve() {

	int prev = 0;
	

	for (int i = 0; i < N; i++) {

		int cost = 1001;

		for (int j = 0; j < 3; j++) {

			if (j != prev || i == 0) {

				if (home[i][j] < cost) {
					cost = home[i][j]; prev = j;
				}
				
			}


		}
		sum += cost;
	}


}


int main() {
	int input;
	cin >> N;
	
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < 3; j++) {
			cin >> input;
			home[i][j] = input;
		}
	}
	
	solve();


	cout << sum;
	return 0;

}