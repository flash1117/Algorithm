#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[9][9];
bool visited[9][9];
vector<pair <int,int>> virus;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0, };


void BFS(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		
		cout << "in BFS"<<curX << curY;


	}

	
}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	for (int i = 0; i < virus.size(); i++) {

		cout << "virus"<< virus[i].first << virus[i].second;
		BFS(virus[i].first, virus[i].second);
	}
		
	

	return 0;
}