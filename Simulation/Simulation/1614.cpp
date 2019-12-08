#include <iostream>

using namespace std;

int N;
long long input;

long long solve() {
	long long ret = 0;
	if (input == 0) return N - 1;
	else if(input % 2==1){
		// 1 -> 8, 2-> 7 3->6 4->5 5->12
		ret = (input - 1) * 8;
		if (N == 1) return ret + 8;
		else if (N == 2) return ret + 7;
		else if (N == 3) return ret + 6;
		else if (N == 4) return ret + 5;
		else if (N == 5) return ret + 12;

	}
	else if (input % 2 == 0) {

		ret = (input - 2) * 8;
		if (N == 1) return ret + 9 + 7;
		else if (N == 2) return ret + 9;
		else if (N == 3) return ret + 10;
		else if (N == 4) return ret + 11;
		else if (N == 5) return (input - 1) * 8 + 12;
	}
}

int main() {

	cin >> N;
	cin >> input;

	cout << solve() << "\n";

	return 0;
}