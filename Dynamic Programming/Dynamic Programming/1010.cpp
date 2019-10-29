#include <iostream>

using namespace std;

#define Endl "\n"

int T, src, dst;

void solve() {

	long long temp = 1, tmp = 1;

	if (src == dst) {
		cout << 1 << Endl;
		return;
	}
	else {

		for (int i = src+1; i <= dst; i++) {
			
			temp *= i;
			tmp *= i - src;

			
		}
		cout << temp << " " << tmp << Endl;
		cout << temp / tmp << Endl;
	}

}

int main() {

	cin >> T;
	while (T--) {

		cin >> src >> dst;

		solve();
	}


	return 0;
}