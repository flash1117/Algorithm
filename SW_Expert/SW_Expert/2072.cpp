#include <iostream>

using namespace std;

int main() {

	int T, cnt =1, ret=0, input;
	cin >> T;

	while (T--) {
		ret = 0;
		for (int i = 0; i < 10; i++) {
			cin >> input;
			if (input % 2 == 1)
				ret += input;
		}
		
		cout << "#" << cnt++ << " " << ret << endl;
	}

	return 0;
}