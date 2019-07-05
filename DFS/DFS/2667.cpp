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

	if (visited[x][y]) 
		return;

	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (!visited[nextX][nextY] && isBoundary(nextX, nextY) && map[nextX][nextY] == 1) {
		//	cout << nextX << " , " << nextY << endl;
			DFS(nextX, nextY, cnt+1);
		}
	}

	vec.push_back(cnt);
}

int main() {

	memset(visited, false, sizeof(visited));
	string temp;
	int area = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) {

			map[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (map[i][j] == 1 && visited[i][j] == false) {
				DFS(i, j, 0);
				area++;
			}
				
		}
	}

	cout << area << endl;

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

	

	return 0;
}