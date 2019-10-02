#include <iostream>

using namespace std;

int N, round=1, team1, team2;

typedef struct {

	int x, y;
}pos;

void solve() {


}

int main() {

	cin >> N >> team1 >> team2;

	int temp = 0;
	if (team1 > team2)
	{
		temp = team2;
		team2 = team1;
		team1 = temp;
	}
	solve();

	return 0;
}