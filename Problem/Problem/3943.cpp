#include <iostream>

using namespace std;

const int MAX_SIZE = 100000 + 1;
int dp[MAX_SIZE];

void makeHailStone() {


	for (int i = 1; i < MAX_SIZE; i++) {

		if (i % 2 == 0) dp[i] = i / 2;

	}


}

int main() {

	ios::sync_with_stdio(false);
	int t,n;
	cin >> t;
	while (t--) {

		cin >> n;


	}
	

	return 0;
}