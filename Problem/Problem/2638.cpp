#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[100][100];
bool visited[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<pair<int, int>> cheesePos;
void initVisitedArray() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

}

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void getMeltCheesePosition(int startX, int startY) {

	queue<pair<int, int>> q;
	q.push(make_pair(startX, startY));
	visited[startX][startY] = true;

	while (!q.empty()) {

		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];

			if (isBoundary(nextX, nextY) && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				if(map[nextX][nextY] == 0)
					q.push({ nextX, nextY });

			}
			else if (isBoundary(nextX, nextY) && visited[nextX][nextY] && map[nextX][nextY] == 1) {

				cheesePos.push_back(make_pair(nextX, nextY));
			
			}
		}
	}


}

void meltCheese() {

	for (int i = 0; i < cheesePos.size(); i++) {

		int X = cheesePos[i].first;
		int Y = cheesePos[i].second;

		map[X][Y] = 0;
	}
}

int getMeltTime() {

	int meltTime = 0;
	while (1) {

		initVisitedArray();

		getMeltCheesePosition(0,0);
		

		if (cheesePos.empty()) {

			return meltTime;
		}
		else {
			meltTime++;
			meltCheese();
			cheesePos.clear();
		}
	}
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;


	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> map[i][j];


		}
	}

	cout << getMeltTime() << "\n";

	return 0;
}