#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> instruction;
vector <int> dice;

int solve() {

	int ret = 0;
	int cur = 0;
	for (int i = 0; i < dice.size(); i++) {

		if (cur >= N - 1) return ret;
		else {

			cur += dice[i];
			ret++;
			
				if(cur >= 1) cur += instruction[cur];
				if (cur < 0) cur = 0;
			
		}
	}
	return ret;
}

int main() {

	int temp;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		instruction.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		dice.push_back(temp);
	}

	cout << solve() << "\n";
	return 0;
}