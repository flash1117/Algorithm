#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {

	int x, y, cnt;

}Coin;


int N, M;
char map[20][20];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<pair<int, int>> pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int solve() {

	queue <Coin> q, q2;

	q.push({ pos[0].first , pos[0].second, 0});
	q2.push({ pos[1].first , pos[1].second, 0 });
	
	while (1) {


		if (q.empty() || q2.empty()) return -1;

		int coin1X = q.front().x;
		int coin1Y = q.front().y;
		int coin1Cnt = q.front().cnt;

		q.pop();


		int coin2X = q2.front().x;
		int coin2Y = q2.front().y;
		int coin2Cnt = q2.front().cnt;

		q2.pop();

		if (coin1Cnt > 10 || coin2Cnt > 10) return -1;

		for (int i = 0; i < 4; i++) {


			int nextX1 = coin1X + dx[i];
			int nextY1 = coin1Y + dy[i];

			int nextX2 = coin2X + dx[i];
			int nextY2 = coin2Y + dy[i];

			if (isBoundary(nextX1, nextY1) && isBoundary(nextX2, nextY2)) {

				if (map[nextX1][nextY1] == '.') {
					q.push({ nextX1, nextY1, coin1Cnt + 1 });
				}
				else {
					q.push({ coin1X, coin1Y, coin1Cnt + 1 });
				}

				if (map[nextX2][nextY2] == '.') {
					q2.push({ nextX2, nextY2, coin2Cnt + 1 });
				}
				else q2.push({ coin2X, coin2Y, coin2Cnt + 1 });

			}
			else if (!isBoundary(nextX1, nextY1) && !isBoundary(nextX2, nextY2));
			else return coin1Cnt + 1;
			
			
		}


	}


	return -1;
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
			if (map[i][j] == 'o') {
				pos.push_back(make_pair(i, j));
				map[i][j] = '.';
			}

		}
	}

	if (pos.size() < 2) {
		cout << -1 << "\n";
		return 0;
	}
	else cout << solve() << "\n";
	
	return 0;
}