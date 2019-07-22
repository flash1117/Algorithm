#include <iostream>

using namespace std;

int main() {

	int T, ret = 0, cnt = 1, input, r;
	cin >> T;

	while (T--) {
		ret = 0;
		
		for (int i = 0; i < 10; i++) {
			cin >> input;
			ret += input;
		}
		r = ret % 10;
		ret /= 10;
		if (r >= 5) ret++;
		cout << "#" << cnt++ << " " << ret << endl;
	}


	return 0;
}