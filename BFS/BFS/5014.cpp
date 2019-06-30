#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int F, S, G, U, D;
bool visited[1000000];

void BFS() {

	queue <int> q;
	q.push(S);
	D = D * (-1);
	int cnt = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			

		}

	}

}

int main() {

	memset(visited, false, sizeof(visited));
	cin >> F >> S >> G >> U >> D;

	BFS();

	return 0;
}