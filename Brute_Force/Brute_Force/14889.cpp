#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N , sum;
int map[20][20], pick[10], pick2[10];
int minNum = 100;

void mk_Team() {

	bool visited[20];
	int index = 0;

	for (int i = 0; i < 20; i++)
		visited[i] = false;

	for (int i = 0; i < N / 2; i++)
		visited[pick[i]] = true;

	for (int i = 0; i < N; i++) 
		if (!visited[i]) pick2[index++] = i;

}

void solve(int depth, int cnt)
{
	if (cnt == N / 2) {

		int team1 = 0, team2 = 0;

		mk_Team();
		for (int i = 0; i < N / 2; i++) {
			
			for (int j = i + 1; j < N / 2; j++) {
				team1 += map[pick[i]][pick[j]];
				team1 += map[pick[j]][pick[i]];
				team2 += map[pick2[i]][pick2[j]];
				team2 += map[pick2[j]][pick2[i]];
			}
		}

		minNum = minNum > abs(team2 - team1) ? abs(team2 - team1) : minNum;

		return;
	}
	else if (depth == N) return;
	

	pick[cnt] = depth;
	solve(depth + 1, cnt + 1); // select
	pick[cnt] = 0;

	solve(depth + 1, cnt); // not select
	
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	solve(0,0);
	cout << minNum << "\n";
	return 0;
}