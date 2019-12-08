#include <iostream>
#include <queue>
#include <string>

using namespace std;
bool isPrime[10000];
bool visited[10000];
int T;
void setPrimeNum() { // Prime Number = false

	for (int i = 2; i < 10000; i++) {

		if (!isPrime[i]) {
			for (int j = 2; j <= 10000 / i; j++) {
				isPrime[i * j] = true;
			}
		}
	}
}

int solve(string src, string dst) {

	int cnt = 0;
	queue <pair<string, int>> q;
	q.push(make_pair(src, 0));

	while (!q.empty()) {

		string cur = q.front().first;
		cnt = q.front().second;

		q.pop();

		if (cur.compare(dst) == 0)
			return cnt;

		for (int i = 0; i < 4; i++) { // 첫째자리 ~ 넷째자리

			for (int j = 0; j < 10; j++) {
				int next = 0;
				if ((cur[i] - '0') == j) continue;
				if (i == 0) {
					if (j == 0) continue;
					else next = j * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + (cur[3] - '0');
				}
				else if (i == 1) 
					next = (cur[0]-'0') * 1000 + j*100 + (cur[2] - '0')*10 + (cur[3] - '0');
				else if (i == 2)
					next = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + j * 10 + (cur[3] - '0');
				else
					next = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + j;
				if (!isPrime[next] && !visited[next]) {
					visited[next] = true;
					string temp = to_string(next);
					q.push({ temp, cnt + 1 });
					
				}
			}
		}
	}
	return -1;
}

void initVisited() {
	for (int i = 1000; i < 10000; i++)
		visited[i] = false;
}

int main() {
	string input1, input2;
	
	cin >> T;
	setPrimeNum();
	while (T--) {
		cin >> input1 >> input2;
		cout << solve(input1, input2) << "\n";
		initVisited();
	}

	return 0;
}