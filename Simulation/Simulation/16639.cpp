#include <iostream>
#include <vector>

using namespace std;

string input;
vector<int> vec;
vector<char> op;
int maxValue;
bool isInitValue;
int calc(char operation, int num1, int num2) {

	switch (operation)
	{
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	default:

		break;
	}
}


void print() {


	for (int i = 0; i < op.size(); i++) {

		cout << vec[i] << op[i];

	}
	cout << endl;
	return;
}



void solve(int depth) {

	if (depth >= input.length()) {

		print();

		vector<int> _num;
		vector<char> _op;


		
		int sum = vec[0];

		for (int i = 0; i < op.size(); i++) {

			if (op[i] == '+' || op[i] == '-' || op[i] == '*') {
				sum = calc(op[i], sum, vec[i + 1]);
			}

		}

		_num.push_back(vec[0]);

		for (int i = 0; i < op.size(); i++) {

			if (op[i] == '+' || op[i] == '-') {

				_op.push_back(op[i]);
				_num.push_back(vec[i+1]);

			}
			else if (op[i] == '*') {

				int cur = _num.back();
				_num.pop_back();
				_num.push_back(calc('*', cur, vec[i + 1]));


			}
			
		}

		int ret = _num[0];
		for (int i = 0; i < _op.size(); i++) {

			ret = calc(_op[i], ret, _num[i + 1]);

		}


		if (!isInitValue) {

			isInitValue = true;
			maxValue = ret;
			maxValue = maxValue > sum ? maxValue : sum;
		}
		else {
			maxValue = maxValue > ret ? maxValue : ret;
			maxValue = maxValue > sum ? maxValue : sum;
		}

		return;
	}

	if (depth == 0) {

		vec.push_back(input[depth] - '0');
		op.push_back(input[depth + 1]);
		solve(depth + 2);
		op.pop_back();
		vec.pop_back();
	}
	else {

		int lastNum = vec.back();
		int lastOp = op.back();
		vec.pop_back();
		op.pop_back();

		vec.push_back(calc(lastOp, lastNum, input[depth] - '0'));
		op.push_back(input[depth + 1]);
		solve(depth + 2);
		vec.pop_back();
		op.pop_back();
		vec.push_back(lastNum);
		op.push_back(lastOp);

		if (depth < input.length() - 1) {

			vec.push_back(calc(input[depth + 1], input[depth] - '0', input[depth + 2] - '0'));
			op.push_back(input[depth + 3]);
			solve(depth + 4);
			op.pop_back();
			vec.pop_back();
		}

		vec.push_back(input[depth] - '0');
		op.push_back(input[depth + 1]);
		solve(depth + 2);
		op.pop_back();
		vec.pop_back();

	
	}
	return;
}


int main() {

	int N;
	cin >> N;
	cin >> input;

	solve(0);

	cout << maxValue << "\n";
	return 0;
}