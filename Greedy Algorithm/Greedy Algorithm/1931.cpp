#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

int N;
vector <pos> vec;
bool visited[100001];

void solve(int start) {

	queue <pos> q;
	q.push({ vec[start].x, vec[start].y });
	visited[start] = true;

	while (!q.empty()) {

		int startTime = q.front().x;
		int endTime = q.front().y;

		q.pop();

		for (int i = 0; i < N; i++) {
			
			if (vec[i].x >= endTime && !visited[i]) {
				visited[i] = true;
				q.push({ vec[i].x, vec[i].y });
				break;
			}
		}

	}

}

int main() {

	int startT, endT, cnt =0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> startT >> endT;
		vec.push_back({startT, endT});
			
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {

		if (!visited[i]) {
			solve(i);
			cnt++;
		}
			
	}
		

	cout << cnt;
	return 0;
}