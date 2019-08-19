#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <int> vec;
int stair[301];

void solve() {

	stair[0] = vec[0];
	stair[1] = vec[1] + stair[0];
	stair[2] = max(vec[2] + vec[1], vec[2] + vec[0]);
	for (int i = 3; i < N; i++) {

		stair[i] = max(vec[i] + vec[i - 1] + stair[i - 3], vec[i] + stair[i - 2]);
	
	}

}


int main() {

	int input;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> input;
		vec.push_back(input);

	}

	solve();
	cout << stair[N - 1];

	return 0;
}