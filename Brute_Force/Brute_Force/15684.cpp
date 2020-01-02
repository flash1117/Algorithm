#include <iostream>
#include <queue>

using namespace std;

int N, M, H;
int map[31][11];
int verticalCnt[11];

bool isCorrectPath(int index) {

	int curY = index;
	queue <pair<int, int>> q;
	q.push(make_pair(1, index));

	while (!q.empty()) {

		int curX = q.front().first;
		curY = q.front().second;

		q.pop();

		if (map[curX][curY] == 1) {
			if (N > curY && map[curX][curY + 1] == 1)
				q.push({ curX, curY + 1 });
			else if (curY > 1 && map[curX][curY - 1] == 1)
				q.push({ curX, curY - 1 });
		}
		else 
			q.push({ curX + 1, curY });

	}

	if (curY == index) return true;
	else return false;
}

int main() {

	pair<int, int> temp;

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> temp.first >> temp.second;
		map[temp.first][temp.second] = 1;
		map[temp.first][temp.second+1] = 1;

		verticalCnt[temp.second]++; verticalCnt[temp.second+1]++;
	}

	return 0;
}