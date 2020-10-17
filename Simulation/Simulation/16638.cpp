#include <iostream>
#include <vector>

using namespace std;

int N;
string input;
vector<int> num;
vector<char> op;
bool isInitValue = true;
int maxRet;

int calc(char operation, int src, int dst) {

	switch (operation)
	{
	case '+' : {
		return src + dst;

	}
	case '-' : {
		return src - dst;

	}
	case '*' : {
		return src * dst;

	}
	default:
		return -1;
	}
}

void print() {

	for (int i = 0; i < op.size(); i++) {
		cout << num[i] << op[i];
	}
	cout << num.back() << endl;

	return;
}

void solve(int depth) {

	if (depth >= input.length()) {

		vector<int> _num;
		vector<char> _op;
		
		_num.push_back(num[0]);
		for (int i = 0; i < op.size(); i++) {

			if (op[i] == '*') {
				int cur = _num.back();
				_num.pop_back();

				cur = cur* num[i + 1];
				_num.push_back(cur);

			}
			else {
				_num.push_back(num[i + 1]);
				_op.push_back(op[i]);
			}

		}
		int cur = _num[0];

		for (int i = 0; i < _op.size(); i++) {
			cur = calc(_op[i], cur, _num[i + 1]);
		}

		if (isInitValue) {
			isInitValue = false;
			maxRet = cur;
		}
		else  maxRet = maxRet > cur ? maxRet : cur;

		return;
	}

	if (depth < input.length() - 1) {

		num.push_back(input[depth] - '0');
		op.push_back(input[depth + 1]);
		solve(depth + 2);
		op.pop_back();
		num.pop_back();

		if (depth + 3 <= input.length() - 1) {

		
			num.push_back(calc(input[depth+1], input[depth] - '0', input[depth+2] - '0'));
			op.push_back(input[depth + 3]);
			solve(depth + 4);
			op.pop_back();
			num.pop_back();

		}
		else if(depth+2 <= input.length() -1 ){
			num.push_back(calc(input[depth + 1], input[depth] - '0', input[depth + 2] - '0'));
			solve(depth + 4);
			num.pop_back();

		}


	}
	else {
		num.push_back(input[depth] - '0');
		solve(depth + 1);
		num.pop_back();

	}

	return;
}

int main() {

	cin >> N;
	cin >> input;

	solve(0);
	cout << maxRet << "\n";

	return 0;
}