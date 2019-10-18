#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string A,B;

int solve(int index) {

	int diff = 0;
	for (int i = 0; i < A.length(); i++) 
		if (A[i] != B[index + i]) diff++;
	
	return diff;
}

int main() {
	int ret = 100;
	cin >> A >> B;

	for (int i = 0; i < B.length(); i++) {
		if (i + A.length() > B.length()) break;
		ret = min(solve(i), ret);
	}
	cout << ret;

	return 0;
}