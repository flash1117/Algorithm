#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> team[2];
vector <int> pick, answer;
long long minDif = -1;

void init() {
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (index < pick.size() && pick[index] == i) {
			index++;
			answer.push_back(1);
		}
		else answer.push_back(2);
	}
}

void setAnswer(bool isSame) {

	int index = 0;
	if (isSame) { // 최소값이 같을 때 정렬
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] == 1 && i < pick[index]) return;
			else if (answer[i] == 1 && i == pick[index]) index++;
			else if (answer[i] == 1 && i > pick[index]) {

				int st = index;
				for (int j = st; j < N; j++) {
					if (index < pick.size() && pick[index] == j) {
						answer[j] = 1;
						index++;
					}
					else answer[j] = 2;
				}

				return;
			}
		}
	}
	else {

		for (int i = 0; i < answer.size(); i++) {

			if (index < pick.size() && i == pick[index]) {
				answer[i] = 1;
				index++;
			}
			else answer[i] = 2;
		}

		return;
	}
}


void solve(int depth , int cnt , long long dif) {

	if (pick.size() == N/2) {

		for (int i = depth; i < N; i++)
			dif -= team[1][i];

		if (minDif == -1) {
			minDif = dif >= 0 ? dif : -dif;
			init();
		}
		else if ((dif < 0 && -dif > minDif) || (dif >= 0 && dif > minDif)) return;
		else if ((dif < 0 && -dif == minDif) || (dif >= 0 && dif == minDif)) setAnswer(true);
		else {
			minDif = dif >= 0 ? dif : -dif;
			setAnswer(false);
		}

		return;
	}
	else if (depth == N) return;

	pick.push_back(depth);
	solve(depth + 1, cnt + 1, dif+team[0][depth]);
	pick.pop_back();

	solve(depth + 1, cnt, dif-team[1][depth]);

}

int main() {

	ios_base::sync_with_stdio(false);

	long long input;
	cin >> N;
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < N; j++) {
			cin >> input;
			team[i].push_back(input);
		}
	}

	solve(0, 0, 0);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}