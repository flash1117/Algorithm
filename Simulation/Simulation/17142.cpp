#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define Endl "\n"
#define INF 987654321

int N, M, ret = INF;
int map[51][51];
vector <pair<int, int>> v;
int pick[10];
int cntVirusMap[51][51];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {
	int x, y, cnt;
}pos;


bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>N-1 || y>N-1) return false;
	return true;

}

int isAllVirus() {
	bool state = true;
	int maxCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] == 0 && cntVirusMap[i][j] != 0) {
				maxCnt = maxCnt > cntVirusMap[i][j] ? maxCnt : cntVirusMap[i][j];
			}
			else if (map[i][j] == 0 && cntVirusMap[i][j] == 0) state = false;

			cntVirusMap[i][j] = 0;
		}
	}
	
	if (!state) return -1;
	else return maxCnt;
}

/*
void print() {


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << cntVirusMap[i][j] << " ";
		}
		cout << Endl;
	}
	cout << "#################" << Endl;
}
*/



void solve() {

	queue <pos> q;

	for (int i = 0; i < M; i++) {
		q.push({ v[pick[i]].first , v[pick[i]].second, 0 });
	}

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;

		q.pop();


		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (map[nextX][nextY] != 1 && isBoundary(nextX, nextY) &&
				(ccnt+1 < cntVirusMap[nextX][nextY] || cntVirusMap[nextX][nextY] == 0))
			{
				q.push({ nextX, nextY, ccnt + 1 });
				cntVirusMap[nextX][nextY] = ccnt + 1;
	//			if (cntVirusMap[nextX][nextY] > 10 && map[nextX][nextY] == 2)
	//			{
					/*
					cout << "cur virus : " << cntVirusMap[nextX][nextY] << endl;
					cout << "cur cnt : " << ccnt << endl;
					cout << "cur X , Y" << curX << " , " << curY << Endl;
					cout << "next X , Y" << nextX << " " << nextY << Endl;
					*/
					
	//			}
			}
		
		}

	}
//	print();
	int temp = isAllVirus();
	if (ret == INF) ret = temp;
	else if (ret == -1 && temp != -1) ret = temp;
	else if (temp != -1)ret = ret > temp ? temp : ret;
}

void spreadVirus(int depth, int cnt) {

	if (depth > v.size()) return;
	else if (cnt == M) {

		solve();

		return;
	}

	pick[cnt] = depth;
	spreadVirus(depth + 1, cnt + 1);
	spreadVirus(depth + 1, cnt);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back(make_pair(i, j));
		}
	
	}

	spreadVirus(0,0);
	cout << ret << Endl;
	return 0;
}