#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 100

int N, M;
int maze[MAX][MAX];
bool visited[MAX][MAX];

typedef struct {
	int y, x, pathLength; // 좌표와 현재까지의 길이

}dir;

int minStep(int y, int x, int pathLength) {

	queue<dir> q;
	int result = 0;
	dir start = { y,x,pathLength };
	q.push(start);


	while (!q.empty()) {

		int curY = q.front().y;
		int curX = q.front().x;
		int curLength = q.front().pathLength;

		if (curY == N - 1 && curX == M - 1) {
			result = curLength;
			break;
		}
		q.pop();
		visited[y][x] = true;

		//east
		if (curX + 1 < M && maze[curY][curX + 1] && !visited[curY][curX + 1]) {

			dir east = { curY, curX + 1, curLength + 1 };
			visited[curY][curX + 1] = true;
			q.push(east);


		}

		//west
		if (curX - 1 >= 0 && maze[curY][curX - 1] && !visited[curY][curX - 1]) {

			dir west = { curY, curX - 1, curLength + 1 };
			visited[curY][curX - 1] = true;
			q.push(west);

		}

		//south
		if (curY + 1 < M && maze[curY + 1][curX] && !visited[curY + 1][curX]) {

			dir south = { curY + 1 , curX, curLength + 1 };
			visited[curY + 1][curX] = true;
			q.push(south);
		}

		//North
		if (curY - 1 >= 0 && maze[curY - 1][curX] && !visited[curY - 1][curX]) {

			dir north = { curY - 1, curX, curLength + 1 };
			visited[curY - 1][curX] = true;
			q.push(north);
		}

	}
	return result;
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
			maze[i][j] = temp[j] - '0';

	}
	memset(visited, false, sizeof(visited));
	cout << minStep(0, 0, 1) << endl;
	return 0;
}