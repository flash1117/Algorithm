#include <iostream>
#include <vector>

using namespace std;

int N, M;
int num[] = { 1,2,3,4,5,6,7 };
int pick[7];

void solve(int depth, int cnt) {

	if (depth > N) return;
	else if (cnt == M) {

		for (int i = 0; i < M; i++)
			cout << pick[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		
		pick[cnt] = i + 1;
		solve(depth + 1, cnt + 1);
		 
	}

}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	solve(0, 0);
	
	return 0;
}