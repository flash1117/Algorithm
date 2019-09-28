#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define Endl "\n"

int N, M;
vector <int> vec;
int num[9];
bool visited[9];

void solve(int depth, int cnt) {

	if (depth == M) {

		for (int i = 0; i < M; i++)
			cout << num[i] << " ";
		cout << Endl;

		return;
	}


	for (int i = cnt; i < N; i++) {

		if (!visited[vec[i]]) {
			num[depth] = vec[i];
			visited[vec[i]] = true;
			solve(depth + 1, cnt);
			visited[vec[i]] = false;
		}
			
	}

}


int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		vec.push_back(i + 1);

	solve(0, 0);

	return 0;
}