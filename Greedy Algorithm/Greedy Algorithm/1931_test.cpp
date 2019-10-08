#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pos pair<int,int>

int N, maxValue;
bool visited[100001];
vector <pos> vec;

void solve(int start) {
	int cnt = 1;
	queue <pos> q;
	q.push({ vec[start].first, vec[start].second });
	visited[start] = true;
	
	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < N; i++) {

			int nextX = vec[i].first;
			if (nextX >= curY) {
				q.push({ vec[i].first, vec[i].second });
				visited[i] = true;
				cnt++;
				break;
			}

		}


	}
	if (cnt > maxValue) maxValue = cnt;
}

int main() {

	int firstTime, secondTime, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> firstTime >> secondTime;
		vec.push_back({ firstTime, secondTime });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << " " << vec[i].second << endl;
	}
	
	for (int i = 0; i < N; i++) {
		if (!visited[i]) 

			solve(i);
			
		
	}

	cout << cnt;
	return 0;
}