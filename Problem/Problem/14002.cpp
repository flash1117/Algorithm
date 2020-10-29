#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> ret;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	auto iter = ret.begin();


	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (ret.empty()) {
			ret.push_back(input);
		}
		else {

			if (ret.back() < input) ret.push_back(input);
			else if (ret.back() > input && ret[ret.size() - 2] < input) {
				ret.back() = input;
			}
			else {

				iter = lower_bound(ret.begin(), ret.end(), input);
				*iter = input;

			}
			

		}

	}

	cout << ret.size() << "\n";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << "\n";



	return 0;
}