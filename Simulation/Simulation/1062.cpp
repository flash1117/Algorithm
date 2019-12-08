#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector <string> input;
vector <pair<int, char>> vec;

int solve() {

	// 무조건 가르쳐야 하는 글자 a n t i c
	if (K < 5) return 0;
	else K -= 5;

	int ret = 0, temp = 0;

	for (int i = 0; i <= ('z' - 'a'); i++)
		vec.push_back(make_pair(0, 'a' + i));

	for (int i = 0; i <= K; i++) { // 중간 문자열 길이

		for (int j = 0; j < input.size(); j++) { // 주어진 Test Case 순회
			temp = 0;
			if (input[j].length() - 8 == 0 && i == 0) ret++; // 초깃값 설정
			else if (input[j].length() - 8 <= i){

				

			}
		}

	}


	return ret;
}


int main() {

	string temp;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		input.push_back(temp);
	}

	cout << solve << "\n";
	return 0;
}