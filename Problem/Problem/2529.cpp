#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<char> vec;
int pick[11];
long long _max = -1, _min = -1;
string maxStr, minStr;

void solve(int depth, int cnt) {

	if (cnt == k + 1) {

		vector<int> _pick;

		for (int i = 0; i < cnt; i++)
			_pick.push_back(pick[i]);

		do {

			bool state = true;
			string numStr = "";
			long long num = 0;

			for (int i = 0; i < k; i++) {

				if (vec[i] == '<') {

					if (_pick[i] < _pick[i + 1]);
					else {
						state = false;
						break;
					}
				}
				else {

					if (_pick[i] > _pick[i + 1]);
					else {
						state = false;
						break;
					}
				}
			}

			if (state) {

//				cout << num << " ";

				for (int i = 0; i < cnt; i++) {

					num *= 10;
					num += _pick[i];
					numStr += to_string(_pick[i]);
				}

				if (_max == -1 && _min == -1) {
					_max = num;
					_min = num;
					maxStr = numStr;
					minStr = numStr;
				}
				else {

					if (_max < num) {
						_max = num;
						maxStr = numStr;
					}

					if (_min > num) {
						_min = num;
						minStr = numStr;
					}


				}

			}

		} while (next_permutation(_pick.begin(), _pick.end()));

		_pick.clear();
		return;
	}

	if (depth >= 10) return;

	pick[cnt] = depth;
	solve(depth + 1, cnt + 1);
	solve(depth + 1, cnt);

	return;
}


int main() {

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		char input;
		cin >> input;
		vec.push_back(input);
	}

	solve(0, 0);

	cout << maxStr << "\n";
	cout << minStr << "\n";

	return 0;
}