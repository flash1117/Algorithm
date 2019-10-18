#include <iostream>
#include <queue>

using namespace std;

int N, L;
int map[101][101];
int visited[101][101];

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

int solve() {

	int ret = 0, cnt=0;

	for (int i = 0; i < N; i++) {


		for (int j = 0; j < N; j++) {


			if (j > 0 && map[i][j] - map[i][j - 1] == 0) {
				visited[i][j] = 1;

			}
			else if (j > 0 && map[i][j] - map[i][j - 1] > 0) {

				visited[i][j - 1] = 1;

			}
			else {
				visited[i][j - 1] = -1;

			}

		}
	}




	return ret;
}

int main() {

	cin >> N >> L;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
		
	solve();
	return 0;
}