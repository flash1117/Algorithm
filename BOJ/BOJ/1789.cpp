#include <iostream>

using namespace std;

// 1 - 1
// 2 - 1
// 3 - 2
// 4 - 2
// 5 - 2
// 6 - 3
// 7 - 3
// 8 - 3
// 9 - 3
// 10 - 4

int main() {
	long long N, sum =0;
	int num = 1;
	cin >> N;
	while (1) {

		sum += num;
		if (sum > N) {
			cout << num - 1 << "\n";
			return 0;
		}
		num++;
	}
	
	return 0;
}