#include <iostream>
#include <vector>

using namespace std;

bool visited[6][6];
vector<pair<int, int>> vec;

int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,2,-2,1,-1 };

bool isProper(int src, int dst) {

	for (int i = 0; i < 8; i++) {

		int nextX = vec[dst].first + dx[i];
		int nextY = vec[dst].second + dy[i];

		if (nextX == vec[src].first && nextY == vec[src].second) return true;
	}
	return false;
}

void solve() {

	if (!isProper(0, 35)) {
		cout << "Invalid";
		return;
	}

	for (int i = 0; i < 36; i++) {

		bool State = false;
		
		if(!visited[vec[i].first][vec[i].second])
			visited[vec[i].first][vec[i].second] = true;
		else {
			cout << "Invalid";
			return;
		}

		if (i > 0) {
			State = isProper(i - 1, i);
			if (!State) {
				cout << "Invalid";
				return;
			}
		}	
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j]) {
				cout << "Invalid";
				return;
			}
		}
	}

	cout << "Valid";
	return;
}

int main() {

	string input;
	for (int i = 0; i < 36; i++) {
		cin >> input;
		vec.push_back(make_pair(input[0] - 'A', input[1] - '1'));
	}
	solve();

	return 0;
}