#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define Endl "\n"

char white[51][51];
char black[51][51];
char map[51][51];

int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

typedef struct {

	int x, y;
	char ch;
}pos;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

void print() {

	cout << Endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << white[i][j] << " ";
		}
		cout << Endl;
	}

	cout << Endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << black[i][j] << " ";
		}
		cout << Endl;
	}


}

void makeChess() {

	queue<pos> q;
	q.push({ 0,0,'W' });
	
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		char ch = q.front().ch;

		q.pop();
		white[curX][curY] = ch;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && white[nextX][nextY] != 'B' && white[nextX][nextY] != 'W')
			{
				if (ch == 'B') 
					q.push({ nextX, nextY, 'W' });
				else 
					q.push({ nextX, nextY, 'B' });
			}
		}
	}

	q.push({ 0,0,'B' });
	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		char ch = q.front().ch;

		black[curX][curY] = ch;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && black[nextX][nextY] != 'B' && black[nextX][nextY] != 'W')
			{
				if (ch == 'B')
					q.push({ nextX, nextY, 'W' });
				else
					q.push({ nextX, nextY, 'B' });
			}
		}
	}

}


int main() {

	cin >> N >> M;

	for(int i =0;i<N;i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}


	makeChess();
	print();



	return 0;
}