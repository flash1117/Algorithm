#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		vec.push_back(input);
	}



	return 0;
}