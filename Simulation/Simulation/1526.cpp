#include <iostream>
#include <vector>

using namespace std;

string N;

int solve() {
	int ret = 0;
	vector <int> vec;

	for (int i = 0; i < N.length(); i++) {

		if (N[i] == '4' || N[i] == '7') {
			vec.push_back(N[i] - '0');
		}
		else {

			if (N[i] < '4') {

				if (vec.empty()) {
					for (int j = i + 1; j < N.length(); j++)
						vec.push_back(7);
				}
				else {
					bool state = false;
					vec.push_back(7);
					for (int j = i - 1; j >= 0; j--) {
						if (vec[j] == 7) {
							vec[j] = 4;
							state = true;
							break;
						}
						else {
							vec[j] = 7;
						}
					}
					if (state);
					else vec.pop_back();
					for (int j = i + 1; j < N.length(); j++)
						vec.push_back(7);
				}
				break;
			}
			else if (N[i] > '4' && N[i] < '7') {
				vec.push_back(4);
				for (int j = i + 1; j < N.length(); j++)
					vec.push_back(7);
				break;
			}
			else { // 8 9
				for (int j = i; j < N.length(); j++)
					vec.push_back(7);
				break;
			}
		}
	}

	int temp = 1;

	while (!vec.empty()) {

		int cur = vec.back();
		vec.pop_back();
		ret += temp * cur;
		temp *= 10;
	}

	return ret;
}

int main() {

	cin >> N;
	cout << solve() << "\n";

	return 0;
}