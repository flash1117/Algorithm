#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string input;
int changeCnt, maxPrice;

void solve(int depth, int cnt) {

	if (cnt == changeCnt || cnt == input.length()) {

		int price = stoi(input);
		maxPrice = maxPrice > price ? maxPrice : price;
		return;
	}


	for (int i = depth; i < input.length(); i++) {

		for (int j = i + 1; j < input.length(); j++) {

			swap(input[i], input[j]);
			solve(i, cnt + 1);
			swap(input[j], input[i]);
		}

	}
	return;
}

void init() {


	maxPrice = 0;
	return;
}

int main() {

	int T, num=0;
	cin >> T;
	while (T--) {

		num++;
		init();

		cin >> input >> changeCnt;
	
		solve(0, 0);

		cout << "#" << num << " " << maxPrice << "\n";
	}


	return 0;
}