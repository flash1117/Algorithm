#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define Pii pair<int,int>

using namespace std;
int N;
char map[101][101];
char blind[101][101];
bool visited[101][101];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return 0;
	return 1;
}

void BFS(int i, int j, bool c) {
	queue<Pii> q;
	char stt;
	if (!c)
		stt = map[i][j];
	else
		stt = blind[i][j];
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		Pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = now.first + dx[i];
			int nextY = now.second + dy[i];
			if (!c) {
				if (inBoundary(nextX,nextY)&&!visited[nextX][nextY] && stt == map[nextX][nextY]) {
					q.push({ nextX,nextY });
					visited[nextX][nextY] = 1;
				}
			}
			else {
				if (inBoundary(nextX,nextY)&&!visited[nextX][nextY] && stt == blind[nextX][nextY]) {
					q.push({ nextX,nextY });
					visited[nextX][nextY] = 1;
				}
			}			
		}
	}
}

void Init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = 0;
}


int main() {

	string input;
	int Ncnt = 0, Ccnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'G')
				blind[i][j] = 'R';
			else
				blind[i][j] = input[j];
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j,0);
				Ncnt++;
			}
		}
	}
	Init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j, 1);
				Ccnt++;
			}
		}
	}
	cout << Ncnt << " " << Ccnt;


	return 0;
}