#include <iostream>
#include <queue>


using namespace std;

typedef struct {

	int x, y, moveCnt, dir, area, startX, startY;
}Pos;

typedef struct {
	int startX, startY, cnt, dir;
}Bridge;


int areaCnt;
int N, M, ret = 101;
int map[10][10];
int _map[10][10];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool visited[10][10];
vector<Bridge> br;
vector<int> pick;

bool isBoundary(int x, int y) {
	if (x< 0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}


void initMap() {

	queue <pair<int, int>> q;
	int area = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {

				area++;
				areaCnt = area;
				q.push(make_pair(i, j));
				visited[i][j] = true;

				while (!q.empty()) {

					int curX = q.front().first;
					int curY = q.front().second;
					q.pop();

					map[curX][curY] = area;

					for (int i = 0; i < 4; i++) {
						int nextX = curX + dx[i];
						int nextY = curY + dy[i];

						if (isBoundary(nextX, nextY) && !visited[nextX][nextY] && map[nextX][nextY] == 1) {
							q.push(make_pair(nextX, nextY));
							visited[nextX][nextY] = true;
						}
					}

				}

				

			}
		}
	}

	return;
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void buildBridge() {

	queue<Pos> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				q.push({ i,j,0,0,map[i][j],i,j });
				q.push({ i,j,0,1,map[i][j],i,j });
				q.push({ i,j,0,2,map[i][j],i,j });
				q.push({ i,j,0,3,map[i][j],i,j });
			}
				
		}
	}

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().moveCnt;
		int curDir = q.front().dir;
		int startArea = q.front().area;
		int startX = q.front().startX;
		int startY = q.front().startY;
		q.pop();

		int nextX = curX + dx[curDir];
		int nextY = curY + dy[curDir];

		if (!isBoundary(nextX, nextY)) continue;
		if (map[nextX][nextY] == startArea) continue;
		if (map[nextX][nextY] != 0 && map[nextX][nextY] != startArea) {

			if (ccnt <= 1) continue;
			else {
				// save position in vector

				br.push_back({ startX, startY, ccnt, curDir });
				continue;
			}
		}

		if (isBoundary(nextX, nextY)) q.push({ nextX, nextY, ccnt + 1, curDir, startArea , startX, startY});

	}

}

void printBridge() {

	for (int i = 0; i < br.size(); i++) {
		cout << br[i].startX << " " << br[i].startY << " " << br[i].cnt << " " << br[i].dir << "\n";
	}
}

int canAllTravel() {

	int brCnt = 0;
	vector<int> graph[100];
	bool areaVisit[100];
	for (int i = 1; i <= areaCnt; i++) {
		areaVisit[i] = false;
	}

	int src = 0, dst = 0;

	for (int i = 0; i < pick.size(); i++) {

		int index = pick[i];

		int curX = br[index].startX;
		int curY = br[index].startY;
		int ccnt = br[index].cnt;
		int dir = br[index].dir;

		
		for (int j = 0; j <= ccnt+1; j++) {
			int nextX = curX + dx[dir] * j;
			int nextY = curY + dy[dir] * j;

			if (map[nextX][nextY] == 0) {
				brCnt++;
			}
			
			if (j == 0) {
				src = map[nextX][nextY];
			}
			else if (j == ccnt + 1) dst = map[nextX][nextY];
		}

		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}
	
//	print();
	queue<int> q;
	q.push(src);
	areaVisit[src] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!areaVisit[next]) {
				q.push(next);
				areaVisit[next] = true;
			}
		}

	}

	for (int i = 1; i <= areaCnt; i++) {
		if (!areaVisit[i]) return -1;
	}

	if (src == 0 || dst == 0) return -1;
	return brCnt;
}

void solve(int depth, int cnt) {

	if (cnt <= areaCnt)
	{
		int brCnt = canAllTravel();
		if (brCnt != -1) {

			ret = ret > brCnt ? brCnt : ret;
		}

	}
	else return;

	if (depth >= br.size()) return;

	pick.push_back(depth);
	solve(depth + 1, cnt + 1);
	pick.pop_back();
	solve(depth + 1, cnt);

	return;
}



int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];


		}
	}

	initMap();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			_map[i][j] = map[i][j];


		}
	}

//	print();
	buildBridge();
//	printBridge();


	solve(0,0);

	if (ret == 101) cout << -1 << "\n";
	else cout << ret<< "\n";
	return 0;
}