#include <iostream>

using namespace std;

int main() {

	int N, sum =0, temp=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sum += temp;
	}
	if (sum > N - sum) cout << "Junhee is cute!\n";
	else cout << "Junhee is not cute!\n";
	return 0;
}