#include <iostream>

using namespace std;

int L, W, R, B;

int main() {

	cin >> R >> B;

	for (int i = 3; i <= R; i++) {
		
		if ((R + B) % i == 0) {
			L = i;
			W = (R + B) / i;
			if ((L - 2) * (W - 2) == B) {
				if (L < W) {
					int tmp = L;
					L = W;
					W = tmp;
				}
				cout << L << " " << W << "\n";
				return 0;
			}
		}

	}
	return 0;
}