#include <iostream>
#include <vector>


using namespace std;

int N, M;
vector <int> truth;
vector <int> party[51];
bool isJudge[51];

bool judge(int index) {

	if (truth.size() == 0) return false;

	for (int i = 0; party[index].size(); i++) {
		for (int j = 0; j < truth.size(); j++) {
			if (party[index][i] == truth[j]) return true;
		}
	}

	return false;
}

bool solve(int index) {

	for (int i = 0; i < party[index].size(); i++) {
		if (isJudge[party[index][i]]) return true;
	}
	return false;
}

int main() {
	
	int temp, temp2;
	cin >> N >> M;
	cin >> temp;
	for (int i = 0; i < temp; i++) {
		cin >> temp2;
		truth.push_back(temp2);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		for (int i = 0; i < temp; i++) {
			cin >> temp2;
			party[i].push_back(temp2);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool state = judge(i);
		if (state) {
			for (int j = 0; j < party[i].size(); j++) {
				isJudge[party[i][j]] = true;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		bool state = solve(i);
		if (!state) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}