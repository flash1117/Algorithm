#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ary[1000001];

void DP() {

	ary[1] = 0;
	for (int i = 2; i <= N; i++) {
		ary[i] = ary[i - 1] + 1;
		if (i % 3 == 0) {
			ary[i] = min(ary[i],ary[i / 3] + 1);
		}
		else if (i % 2 == 0) {
			ary[i] = min(ary[i],ary[i / 2] + 1);
		}

	}
}

int main() {

	cin >> N;
	DP();


	cout << ary[N];
	return 0;
}