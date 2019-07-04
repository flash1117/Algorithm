#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int map[26][26];
bool visited[26][26];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <int> vec;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;

}

void DFS(int x, int y, int cnt) {

	if (visited[x][y]) {
		vec.push_back(cnt);
		cnt = 0;
		return;
	}

	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (!visited[nextX][nextY] && isBoundary(nextX, nextY) && map[nextX][nextY] == 1) {
			cout << nextX << " , " << nextY << endl;
			DFS(nextX, nextY, cnt+1);
		}
	}

}

int main() {

	memset(visited, false, sizeof(visited));
	string temp;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) {

			map[i][j] = temp[j] - '0';
		}
	}

	DFS(0, 0, 0);


	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	return 0;
}