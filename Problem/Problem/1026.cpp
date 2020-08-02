#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	vector <int> A, B;

	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		A.push_back(input);

	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		B.push_back(input);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>() );

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];

	}

	cout << sum << "\n";
	return 0;
}