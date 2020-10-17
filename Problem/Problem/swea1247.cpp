#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> company;
pair<int, int> house;
vector<pair<int, int>> customer;
vector<int> index;

void init() {

	company = make_pair(0, 0);
	house = make_pair(0, 0);
	customer.clear();
	index.clear();
	return;
}


int solve() {

	int _max = 987654321;
	do {
	//	cout << "\n";
		int dist = abs(company.first - customer[index[0]].first) + abs(company.second - customer[index[0]].second);
		for (int i = 0; i < index.size() - 1; i++) {
	//		cout << customer[index[i]].first << " " << customer[index[i]].second << "\n";
			dist += abs(customer[index[i]].first - customer[index[i + 1]].first) + abs(customer[index[i]].second - customer[index[i + 1]].second);
		}
	//	cout << customer[index[index.size() - 1]].first << " " << customer[index[index.size() - 1]].second << "\n";
		
		dist += abs(customer[index[index.size()-1]].first - house.first) + abs(customer[index[index.size()-1]].second - house.second);

		_max = _max > dist ? dist : _max;

	} while (next_permutation(index.begin(), index.end()));


	return _max;
}

int main() {

	int t, num =0;
	cin >> t;
	while (t--) {

		init();
		num++;

		int N;
		cin >> N;

		cin >> company.first >> company.second;
		cin >> house.first >> house.second;
		
		for (int i = 0; i < N; i++) {
			pair<int, int> input;
			cin >> input.first >> input.second;
			customer.push_back(input);
			index.push_back(i);
		}



		cout << "#" << num << " " << solve() << "\n";
	}


	return 0;
}