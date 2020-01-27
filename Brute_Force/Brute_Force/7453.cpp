#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret;
vector <long long> sum1, sum2; // A+B array , C+D array
vector <long long> A, B, C, D;

int main() {

	long long a, b, c, d;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum1.push_back(A[i] + B[j]);
			sum2.push_back(C[i] + D[j]);
		}
	}

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());

	for (int i = 0; i < sum1.size(); i++) {
		
		if (sum1[i] <= 0) {
			int st = sum2.size() - 1;
			for (int j = st; j >= 0; j--) {

			}
		}
		else {
			for (int j = 0; j < sum2.size(); j++) {


			}
		}

	}
	cout << ret << "\n";
	return 0;
}