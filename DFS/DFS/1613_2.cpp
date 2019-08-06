#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, k, s;
bool isCheck;
vector <int> history[401];
vector <int> ristory[401];

bool visited[401];

int BFS(int src, int dst) {

	queue <int> q;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (cur == dst)
			return -1;

		for (int i = 0; i < history[cur].size(); i++) {

			int next = history[cur][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
				cout << "cur :" << cur << "next : " << next << endl;
			}
		}
	}

	return 0;
}


int RBFS(int src, int dst) {

	queue <int> q;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();


		if (cur == dst)
			return 1;

		for (int i = 0; i < ristory[cur].size(); i++) {

			int next = ristory[cur][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}

	return 0;

}
int main() {

	int input1, input2;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {

		cin >> input1 >> input2;
		history[input1].push_back(input2);
		ristory[input2].push_back(input1);

	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		memset(visited, false, sizeof(visited));
		cin >> input1 >> input2;
		int ret = BFS(input1, input2);
		cout << endl;
		if (ret == -1) {
//			cout << ret << endl;
			continue;
		}
		else {
			memset(visited, false, sizeof(visited));
		//	cout << RBFS(input1, input2) << endl;
		}
	}

	return 0;
}