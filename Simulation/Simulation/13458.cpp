#include <iostream>
#include <vector>

using namespace std;

int N, Ai, cnt1, cnt2;
vector <int> testPlace;

long long solve() {

	long long ret = 0;

	for (int i = 0; i < testPlace.size(); i++) {

		testPlace[i] -= cnt1;
		if (testPlace[i] <= 0) ret++;
		else if (testPlace[i] % cnt2 == 0) ret += (long long)(testPlace[i] / cnt2) +1;
		else ret += (long long)(testPlace[i] / cnt2) + 2;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Ai;
		testPlace.push_back(Ai);
	}
	cin >> cnt1 >> cnt2;

	cout << solve() << "\n";

	return 0;
}