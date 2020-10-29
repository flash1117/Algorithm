#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> vec;

void print() {

	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << " ";
	}
	cout << "\n";

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	auto iter = vec.begin();

	cin >> N;
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;

		if (vec.empty()) vec.push_back(input);
		else {

			if (vec.back() < input) vec.push_back(input);
			else if (vec.back() > input && vec[vec.size() - 2] < input) {
				vec.back() = input;
			}
			else if (vec.back() == input);
			else {

				iter = lower_bound(vec.begin(), vec.end(), input);
				*iter = input;

			}

		}

//		print();
	}

	cout << vec.size() << "\n";

	return 0;
}