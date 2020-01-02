#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {

	string num;
	int strike, ball;
}baseball;

vector <baseball> tc;
vector <int> vec = { 1,2,3,4,5,6,7,8,9 };
vector <int> gameNum;
int ret, N;

void solve(int depth, int cnt) {

	if (cnt == 3) {
		vector<int> temp = gameNum;
		do {
			int sCnt = 0, bCnt = 0;
			for (int i = 0; i < N; i++) {

				sCnt = 0; bCnt = 0;
				if (temp[0] == tc[i].num[0] - '0') sCnt++;
				else if (temp[0] == tc[i].num[1] - '0' || temp[0] == tc[i].num[2] - '0') bCnt++;

				if (temp[1] == tc[i].num[1] - '0') sCnt++;
				else if (temp[1] == tc[i].num[0] - '0' || temp[1] == tc[i].num[2] - '0') bCnt++;

				if (temp[2] == tc[i].num[2] - '0') sCnt++;
				else if (temp[2] == tc[i].num[1] - '0' || temp[2] == tc[i].num[0] - '0') bCnt++;

				if (sCnt != tc[i].strike || bCnt != tc[i].ball) break;
				else if (i == N - 1 && sCnt == tc[i].strike && bCnt == tc[i].ball)
					ret++;
			}

		} while (next_permutation(temp.begin(), temp.end()));
		temp.clear();
		return;
	}

	if (depth < vec.size()) {
		gameNum.push_back(vec[depth]);
		solve(depth + 1, cnt + 1);
		gameNum.pop_back();

		solve(depth + 1, cnt);
	}
}
int main() {

	baseball input;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> input.num >> input.strike >> input.ball;
		tc.push_back(input);
	}
	
	solve(0, 0);
	cout << ret << "\n";


	return 0;
}