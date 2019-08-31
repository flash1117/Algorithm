#include <iostream>
#include <algorithm>

using namespace std;


bool cmp(char a, char b) {

	if (a > b) return true;
	return false;
}


int main() {
	
	string N;
	cin >> N;

	long long ret = 0;
	bool isZero = false;

	for (int i = 0; i < N.length(); i++) {

		ret += (N[i] - '0');
		if (!(N[i] - '0')) isZero = true;
	}

	if (ret % 3 || !isZero) cout << -1;

	else {
		sort(N.begin(), N.end(), cmp);
		cout << N;
	}

	return 0;
}