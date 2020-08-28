#include <iostream>

using namespace std;


int n, m;
int pick[10];

void solve(int depth, int cnt) {

	if (depth > n-1) return;
	else if (cnt == m) {

		for (int i = 0; i < m; i++)
			cout << pick[i]+1 << " ";
		cout << "\n";
		return;
	}

		pick[cnt] = depth;
		solve(depth , cnt + 1);
	//	solve(depth + 1, cnt + 1);
		solve(depth + 1, cnt);

	
	
	return;
}

int main() {

	
	cin >> n >> m;

	solve(0, 0);


	return 0;	
}