#include <iostream>
#include <vector>


using namespace std;

int cardCnt[100001];
int N, M;
vector <int> card;
vector <int> ret;
int sum = 0;
void solve(int depth, int cnt) {

	if (cnt == 3) {
		int temp = 0;
		for (int i = 0; i < 3; i++) {
			temp += ret[i];
		}
		
		if (temp <= M && temp > sum) sum = temp;
		return;
	}

	for (int i = depth; i < card.size(); i++) {

		if (ret.empty() || card[i] > ret.back())
			ret.push_back(card[i]);
		else continue;
		solve(depth + 1, cnt + 1);
		ret.pop_back();

	}
}
int main() {

	cin >> N >> M;
	int input , maxCard = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		card.push_back(input);
		cardCnt[input]++;
		maxCard = input > maxCard ? input : maxCard;
	}

	solve(0, 0);
	cout << sum << "\n";

	/*
	else {
		for (int i = 0; i <= maxCard; i++) {
			if (sum == M) break;
			if (cardCnt[i] >= 3) {
				if (3 * i <= M && 3 * i > sum) sum = 3 * i;
				else if(2*i <= M) {

					for (int j = M - 2 * i; j >= 0; j--) {
						if (cardCnt[j] > 0 && 2 * i + j > sum && 2 * i + j <= M)
							sum = 2 * i + j;
					}

				}
			}
			else if (cardCnt[i] == 2) {
				if (2 * i <= M) {

					for (int j = M - 2 * i; j >= 0; j--) {
						if (cardCnt[j] > 0 && 2 * i + j > sum && 2 * i + j <= M)
							sum = 2 * i + j;
					}

				}
			}
		}

		cout << sum << "\n";
	}
	*/
	
	
	return 0;
}