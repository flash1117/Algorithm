#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = 987654321;

int N, minDist = INF;
int pNum[11];
vector<int> rel[11];
bool check[11];
vector<int> area1, area2;

bool isConnectArea1() {

	bool visited[11];
	for (int i = 0; i < 11; i++) visited[i] = false;

	queue<int> q;
	q.push(area1[0]);
	visited[area1[0]] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < rel[cur].size(); i++) {

			for (int j = 1; j < area1.size(); j++) {

				if (area1[j] == rel[cur][i] && !visited[area1[j]]) {
					visited[area1[j]] = true;
					q.push(area1[j]);
				}
			}
		}

	}

	for (int i = 0; i < area1.size(); i++) {
		if (!visited[area1[i]]) return false;
	}

	return true;

}


bool isConnectArea2() {

	bool visited[11];
	for (int i = 0; i < 11; i++) visited[i] = false;

	queue<int> q;
	q.push(area2[0]);
	visited[area2[0]] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < rel[cur].size(); i++) {

			for (int j = 1; j < area2.size(); j++) {

				if (area2[j] == rel[cur][i] && !visited[area2[j]]) {
					visited[area2[j]] = true;
					q.push(area2[j]);
				}
			}
		}

	}

	for (int i = 0; i < area2.size(); i++) {
		if (!visited[area2[i]]) return false;
	}

	return true;

}

int getDist(int x, int y) {

	if (x >= y) return x - y;
	else return y - x;

}

void solve(int depth, int cnt) {

	if (depth > N) {

		if (area1.size() == 0 || area1.size() == N) return;

		for (int i = 1; i <= N; i++) {
			if (!check[i]) area2.push_back(i);
		}
		int sum1 = 0, sum2 = 0;
		if (isConnectArea1() && isConnectArea2()) {

			for (int i = 0; i < area1.size(); i++) {
				sum1 += pNum[area1[i]];
			}

			for (int i = 0; i < area2.size(); i++) {
				sum2 += pNum[area2[i]];
			}

			int d = getDist(sum1, sum2);
			minDist = minDist > d ? d : minDist;
		}

		area2.clear();
		return;
	}

	area1.push_back(depth);
	check[depth] = true;
	solve(depth + 1, cnt + 1);
	area1.pop_back();
	check[depth] = false;
	solve(depth + 1, cnt);

	return;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pNum[i];
	}

	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		for (int j = 0; j < input; j++) {
			int num;
			cin >> num;
			rel[i].push_back(num);

		}


	}

	solve(1, 0);

	if (minDist == INF) cout << -1 << "\n";
	else cout << minDist << "\n";

	return 0;
}