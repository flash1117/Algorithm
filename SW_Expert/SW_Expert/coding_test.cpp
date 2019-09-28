#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[1001];
int N;
vector <pair<int, int>> vec;


void minToilet(int input) {

	queue <pair<int, int>> q;
	visited[input] = true;
	q.push({ vec[input].first , vec[input].second });

	while (!q.empty()) {

		int in = q.front().first;
		int out = q.front().second;

		q.pop();

		for (int i = 0; i < vec.size(); i++) {

			if (!visited[i] && vec[i].first >= out) {
				q.push({ vec[i].first, vec[i].second });
				visited[i] = true;
				break;
			}
		}
	}

}

int main(void) {
	int input, output, ret =0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input >> output;
		vec.push_back({ input, output });

	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {

		if (!visited[i]) {
			minToilet(i); ret++;
		}
	}

	cout << ret;

	return 0;
}