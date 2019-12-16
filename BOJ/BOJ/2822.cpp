#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector <pair<int,int>> input;
	vector <int> order;
	int temp;
	for (int i = 0; i < 8; i++) {
		cin >> temp;
		input.push_back(make_pair(temp, i + 1));
	}
	sort(input.begin(), input.end());
	int sum = 0;
	for (int i = input.size() - 1; i > 2; i--) {
		sum += input[i].first;
		order.push_back(input[i].second);
	}
	cout << sum << "\n";
	sort(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++)
		cout << order[i] << " ";
	return 0;
}