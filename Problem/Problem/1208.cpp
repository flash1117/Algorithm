#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int N, S;
int arr[41];
map<int, int> m1;
map<int, int> m2;
void makeComb(int depth, int sum, bool isRight, bool state) {

	if (state) {
		if (isRight) m1[sum]++;
		else m2[sum]++;
	}


	if (isRight && depth > N / 2) return;
	else if(!isRight && depth >= N) return;

	makeComb(depth + 1, sum + arr[depth], isRight, true);
	makeComb(depth + 1, sum , isRight, false);

	return;
}

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	makeComb(0, 0, true, false);
	makeComb(N/2+1, 0, false, false);

	auto iter1 = m1.begin();
	auto iter2 = m2.end();




	return 0;
}