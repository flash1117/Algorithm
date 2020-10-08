#include <iostream>
#include <vector>

using namespace std;

int N;
vector <char> op;
vector<int> num;
int pick[20];

int solve(int index1, int index2) {

	if (index2 >= op.size()) return 0;

	if (op[index2] == '+') {

		int sum1 = num[index1] + solve(index1 + 1, index2 + 1);

	}
	else if (op[index2] == '-') {

	}
	else { // *

	}


	

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		char input;
		cin >> input;
		if (input >= '0' && input <= '9') {
			num.push_back(input - '0');

		}
		else {
			op.push_back(input);

		}
	}


	return 0;
}