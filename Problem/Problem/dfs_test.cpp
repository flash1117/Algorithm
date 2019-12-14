#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector <int> input;
vector <int> inputCnt = { 0,0,0,0,0,0,0,0,0,0};
vector <int> ret;
int answer = 0;

bool isPrime[10000001]; // false is prime number

void initValue(string& number) {

	for (int i = 0; i < number.length(); i++) {
		input.push_back(number[i] - '0');
		inputCnt[number[i] - '0']++;
	}

	isPrime[0] = true; isPrime[1] = true;
	int dpLen = 1;
	for (int i = 0; i < number.length(); i++)
		dpLen *= 10;

	for (int i = 2; i < dpLen; i++) {
		if (!isPrime[i]) {
			for (int j = 2; j <= dpLen / i; j++)
				isPrime[i * j] = true;
		}
	}
}

void dfs(int depth, int cnt) {

	if (cnt > input.size()) return;

	vector <int> temp = ret;
	do {
		int digit = 1, sum = 0;
		if (temp[0] == 0) continue;
		for (int i = temp.size() - 1; i >= 0; i--) {
			sum += temp[i] * digit;
			digit *= 10;
		}

		if (!isPrime[sum]) answer++;
	} while (next_permutation(temp.begin(), temp.end()));
	if(!temp.empty()) temp.clear();

	for (int i = depth; i < input.size(); i++) {

		if (ret.empty()) {
			ret.push_back(input[i]);
			inputCnt[input[i]]--;
			dfs(depth + 1, cnt + 1);
			inputCnt[ret.back()]++;
			if (!ret.empty()) ret.pop_back();
		}
			
		else if (ret.size() > 1 && input[i] >= ret.back() && inputCnt[input[i]] > 0) {
			ret.push_back(input[i]);
			inputCnt[input[i]]--;
			dfs(depth + 1, cnt + 1);
			inputCnt[ret.back()]++;
			if (!ret.empty()) ret.pop_back();
		}
		
		
	}


}


int main() {


	string numbers = "17";

	initValue(numbers);
	dfs(0, 0);

	cout << answer << endl;

	return 0;
}