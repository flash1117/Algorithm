#include <iostream>
#include <queue>
#define Pii pair<int,int>

using namespace std;

int N, M,K;
bool land[51][51];
bool visited[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			land[i][j] = 0;
		}
}

void BFS(int x,int y) {
	queue<Pii> q;
	q.push({ x,y });
	visited[x][y] = 1;
	
	while (!q.empty()) {
		Pii now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.first + dx[i];
			int nextY = now.second + dy[i];
			if (land[nextX][nextY] && !visited[nextX][nextY]) {
				q.push({ nextX,nextY });
				visited[nextX][nextY] = 1;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		int x, y;
		int cnt = 0;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			land[x][y] = 1;
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if (land[i][j] && !visited[i][j]) {
					BFS(i, j);
					cnt++;
					//Print();
				}					
		Init();
		cout << cnt << endl;
	}

	return 0;
}