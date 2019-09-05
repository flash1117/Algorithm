#include <iostream>

using namespace std;

int N, M, K;
int maxTeam, extraP;

int solve() {

	if (N > 2 * M) {

		maxTeam = M;
		extraP = N - 2 * M;
		
	

	}

	else if (N < 2 * M) {

		maxTeam = N;
		extraP = 2 * M - N;
	}

	else {

		maxTeam = M;
		extraP = 0;
	}


}


int main() {

	cin >> N >> M >> K;
	solve();



	return 0;
}