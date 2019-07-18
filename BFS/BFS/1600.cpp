#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int K, W, H;
int map[201][201];
bool visited[201][201];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int hdx[] = { -2,-2,-1,-1,1,1,2,2 };
int hdy[] = { 1,-1,-2,2,-2,2,-1,1 };

typedef struct {

	int x, y, cnt, hcnt;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>H - 1 || y>W - 1) return false;
	return true;
}

void print() {

	cout << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int BFS() {
	int minD = 401;
	queue <pos> q;
	visited[0][0] = true;
	q.push({ 0,0,0,0});

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int ccnt = q.front().cnt;
		int hcnt = q.front().hcnt;

		q.pop();
		if (curX == H - 1 && curY == W - 1) {

			if (minD > ccnt) { 
				minD = ccnt; 
				if (hcnt > K) {
					for (int i = 0; i < hcnt - K; i++)
						minD += 2;
				}
			}
		}
			

		for (int i = 0; i < 4; i++) {

			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && map[nextX][nextY] != 1 && !visited[nextX][nextY]) {

				visited[nextX][nextY] = true;
				q.push({ nextX, nextY, ccnt + 1, hcnt });

			}

		}
		if (K != 0) {
			
			for (int i = 0; i < 8; i++) {
				int nextX = curX + hdx[i];
				int nextY = curY + hdy[i];

				if (isBoundary(nextX, nextY) && map[nextX][nextY] != 1 && !visited[nextX][nextY])
				{
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY , ccnt + 1 ,hcnt + 1 });
				//	map[nextX][nextY] = 2;
				}
			}

		}
	//	print();
	}

	if (minD == 401)
		return -1;
	else
		return minD;

}

int main() {

	memset(visited, false, sizeof(visited));
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++) 
		for (int j = 0; j < W; j++) 
			cin >> map[i][j];
		
	
	int ret = BFS();

	cout << ret;

	return 0;
}