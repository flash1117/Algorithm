#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int map[301][301];
bool visited[301][301];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int area;

void DFS(int x, int y) {

	visited[x][y] = true;



}

int main() {

	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
		}
	}

	while (1) {
		area = 0;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < M; j++) {

				if (map[i][j] > 0 && !visited[i][j])
					{
						DFS(i, j);
						area++;
					}
			}
		}
		
		if(area >1)
			break;
	}


	return 0;
}