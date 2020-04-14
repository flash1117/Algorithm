#include <iostream>
#include <vector>

using namespace std;

vector<int> A = { 5,5,5,5,5 };
int st[100001];

int solution() {
	
	for (int i = 0; i < A.size(); i++) {
		long long index = A[i];
		if (index > 100000) continue;
		else st[index]++;
	}

	int maxNum = 0;
	for (int i = 0; i <= A.size(); i++) {
		if (st[i] == i) maxNum = i;
	}
	return maxNum;
}

int main() {

	int ret = solution();
	
	cout << ret << endl;
	return 0;
}