#include <iostream>
#include <vector>


using namespace std;

vector <pair<int, char>> input;

int solve(int K) {

	int timeLimit = 210;

	for (int i = 0; i < input.size(); i++) {

		timeLimit -= input[i].first;
		if (K > 8) K = 1;
		if (timeLimit <= 0) return K;
		if (input[i].second == 'T') K++;
		
	}

	return K;
}

int main() {

	int K, T;
	int input1; char input2;
	cin >> K;
	cin >> T;
	while (T--) {
		cin >> input1 >> input2;
		input.push_back(make_pair(input1, input2));
	}

	cout << solve(K) << "\n";

	return 0;
}