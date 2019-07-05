#include <iostream>
#include <cstring>

using namespace std;

int digit(int x) {

	int count = 0;

	while (x > 0) {

		x /= 10;
		count++;
	}

	return count;

}

int main() {

	int T;
	int cnt = 1, ret = 0;
	int temp, q;
	
	cin >> T;

	while (T--) {

		cin >> temp;

		for (int j = 0; j < digit(temp); j++) {
			q = temp * 10;
		}

		for (int i = 1; i <= temp; i++) {

			if (q % i == 0)
				ret++;
		}

		cout << "#" << cnt++ << " " << ret <<endl;
		ret = 0;
	}


	return 0;
}