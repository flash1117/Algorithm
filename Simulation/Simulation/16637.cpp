#include <iostream>
#include <vector>

using namespace std;

const int INF = -987654321;
int N;
string input;
vector<int> num;
vector<char> op;

int _max = INF;
int changeCnt;

void solve(int depth) {

	if (depth >= input.length()) {
		
		int cur = num[0];

		for (int i = 0; i < op.size(); i++) {

			if (op[i] == '+') {
				cur = cur + num[i + 1];
			}
			else if (op[i] == '-') {
				cur = cur - num[i + 1];
			}
			else { // *
				cur = cur * num[i + 1];
			}
		}

		if (changeCnt == 0) {
			_max = cur;
			changeCnt++;
		}
		else {

			_max = _max > cur ? _max : cur;
		}


		return;
	}


	if (depth < input.length()-1) {

		num.push_back(input[depth] - '0');
		op.push_back(input[depth + 1]);
		solve(depth + 2);
		num.pop_back();
		op.pop_back();


		int ret = 0;
		if (input[depth + 1] == '*') {
			ret = (input[depth] - '0') * (input[depth + 2] - '0');
		}
		else if (input[depth + 1] == '+') {
			ret = (input[depth] - '0') + (input[depth + 2] - '0');
		}
		else if (input[depth + 1] == '-') {
			ret = (input[depth] - '0') - (input[depth + 2] - '0');
		}

		if (depth + 3 >= input.length() -1 ) {
			num.push_back(ret);
			solve(depth + 3);
			num.pop_back();
		}
		else {
			num.push_back(ret);
			op.push_back(input[depth + 3]);
			solve(depth + 4);
			op.pop_back();
			num.pop_back();

		}


	}
	else {

		num.push_back(input[depth] - '0');
		solve(depth + 2);
		num.pop_back();

	}

	return;
}

int main() {

	cin >> N >> input;

	solve(0);
	cout << _max << "\n";
	return 0;

}