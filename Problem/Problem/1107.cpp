#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m, digit, nearNum = 100;
bool errBtn[10];
vector <int> usefulBtn;
int pick[10];

int getDigit(int num) {

	int ret = 0;

	while (num) {

		num /= 10;
		ret++;

	}
	return ret;
}

int getDist(int a, int purpose) {

	if (a >= purpose) return a - purpose;
	else return purpose - a;

}


void findNearNum() {

	queue<pair<int, int>> q;
	q.push({ 0,0 });


	while (!q.empty()) {

		int _num = q.front().first;
		int _digit = q.front().second;

		q.pop();

		if (_digit !=0 && getDist(nearNum, n) > getDist(_num, n)) {
			nearNum = _num;
		}

		for (int i = 0; i < usefulBtn.size(); i++) {

			if (_digit + 1 <= digit + 1) {


				int next = _num * 10 + usefulBtn[i];
				q.push({ next, _digit + 1 });

			}
		}

	}
	return;
}

int main() {

	int answer = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		errBtn[input] = true;
	}

	for (int i = 0; i < 10; i++) {
		if (!errBtn[i]) usefulBtn.push_back(i);
	}

	if (n != 0) digit = getDigit(n);
	else digit = 1;

	findNearNum();

	if (nearNum == 100) {

		answer = getDist(nearNum, n);
	}
	else {
	//	cout << "near num : " << nearNum << "!!\n";
		answer += getDist(nearNum, n);
		if (nearNum == 0) answer += 1;
		else answer += getDigit(nearNum);

		answer = answer > getDist(100, n) ? getDist(100, n) : answer;


	}

	cout << answer << "\n";

	return 0;
}