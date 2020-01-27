#include <iostream>
#include <vector>
int T;

using namespace std;

vector <int> vec;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int input =0, tc=0, ret=0, num=1;

	cin >> T;
	while (T--) {
		ret = 0;
		vec.clear();
		cin >> tc;

		for (int i = 0; i < tc; i++) {
			cin >> input;
			if (input == 0 && !vec.empty()) vec.pop_back();
			else vec.push_back(input);

		}

		for (int i = 0; i < vec.size(); i++) {
			ret += vec[i];
		}

		cout << "#" << num++ << " " << ret << "\n";
	}

	return 0;
}