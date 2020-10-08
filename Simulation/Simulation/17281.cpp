#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> od;
vector<int> _od;
vector<int> inning[51];
bool isExist[4];

void initOrder() {

	for (int i = 1; i < 9; i++) {
		_od.push_back(i);
	}
	return;
}

int calcScore(int hitScale) {
	int score = 0;

	if (hitScale == 4) {

		for (int i = 0; i < 4; i++) {
			if (isExist[i]) {
				isExist[i] = false;
				score++;
			}
		}

		score++;
	}
	else {

		for (int i = 3; i >= 0; i--) {

			if (isExist[i] && i + hitScale >= 4) {
				score++;
				isExist[i] = false;

			}
			else if (isExist[i] && i + hitScale < 4) {
				isExist[i] = false;
				isExist[i + hitScale] = true;
			}
		}

		isExist[hitScale] = true;


	}

	return score;

}

int getScore() {
	int lastPlayer = -1;
	int score = 0;
	int out = 0;
	
	
	for (int i = 1; i <= N; i++) { // 1ÀÌ´× ºÎÅÍ NÀÌ´× ±îÁö

		/////// init
		for (int j = 0; j < 4; j++) isExist[j] = false;
		out = 0;
		///////


		while (out < 3) {
			int index = lastPlayer + 1;

			if (inning[i][od[index]] == 0) {
				out++;
			}
			else  { // ¾ÈÅ¸
				score += calcScore(inning[i][od[index]]);


			}

			if (index < 8) lastPlayer = index;
			else lastPlayer = -1;
			
		}

	}

	return score;

}

int solve() {

	int maxScore = 0;
	initOrder();

	do {

		for (int i = 0; i < 9; i++) {

			if (i == 3) {
				od.push_back(0);
			
			}
			else if(i<3) od.push_back(_od[i]);
			else if(i>3) od.push_back(_od[i-1]);
		}



			int score = getScore();
			maxScore = score > maxScore ? score : maxScore;

			od.clear();
		

	} while (next_permutation(_od.begin(), _od.end()));

	return maxScore;
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < 9; j++) {

			int input;
			cin >> input;
			inning[i + 1].push_back(input);
		}
	}

	cout << solve() << "\n";

	return 0;
}