#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[100][100];
bool visited[101];
bool _visited[100][100];

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

bool BFS(int num) {

	queue<pair<int, int>> q;
	

}


int main() {

	int t, num = 0;
	cin >> t;
	while (t--) {

		for (int i = 0; i < 101; i++)
			visited[i] = false;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				_visited[i][j] = false;

		num++;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				cin >> map[i][j];
				visited[map[i][j]] = true;
			}
		}

		for (int i = 0; i < 101; i++) {

			if (visited[i]) {
				BFS(i);

			}
		}

	

		bool state;
		if (state) cout << "#" << num << " YES\n";
		else cout << "#" << num << " NO\n";
	
	}






	return 0;
}