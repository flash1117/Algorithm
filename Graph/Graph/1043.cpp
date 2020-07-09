#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool knowTruth[51];
vector <int> tc[50]; // test case
int rel[51][51];

int main() {


	int t;
	cin >> n >> m;
	cin >> t;

	queue<int> q;


	for (int i = 0; i < t; i++) {
		int input;
		cin >> input;
		knowTruth[input] = true;
		q.push(input);
	}

	for (int i = 0; i < m; i++) {
		int participateNum;
		cin >> participateNum;

		for (int j = 0; j < participateNum; j++) { // input
			int partyPeople;
			cin >> partyPeople;
			tc[i].push_back(partyPeople);
		}

		for (int j = 0; j < tc[i].size(); j++) { // make map
			int cur = tc[i][j];
			for (int k = 0; k < tc[i].size(); k++) {
				int next = tc[i][k];
				rel[cur][next] = 1;
			}
		}

	}

	
	while (!q.empty()) {

		int cur = q.front();
		knowTruth[cur] = true;

		q.pop();

		for (int i = 1; i <= n; i++) {

			int next = rel[cur][i];

			if (rel[cur][i] == 1 && !knowTruth[i]) {

				q.push(i);
				knowTruth[i] = true;
				rel[cur][i] = 2;
				rel[i][cur] = 2;
			}
		}

	}

	int index = 0, ret =0;
	while (!tc[index].empty()) {

		bool state = true;
		for (int i = 0; i < tc[index].size(); i++) {
			if (knowTruth[tc[index][i]]) {
				state = false;
				break;
			}
		}

		if (state) ret++;

		index++;

	}

	cout << ret << "\n";

	return 0;
}