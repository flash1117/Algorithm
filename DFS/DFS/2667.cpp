#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt , max_cnt=0;
int map[26][26];
bool visited[26][26];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <int> vec;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;

}

int DFS(int x, int y) {
	if (!isBoundary(x,y)||visited[x][y]||!map[x][y]) return 0;

	visited[x][y] = true;
	int cnt = 1;

	for (int i = 0; i < 4; i++) {

		int nextX = x + dx[i];
		int nextY = y + dy[i];
		cnt += DFS(nextX, nextY);
	}
	return cnt;
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

			if (map[i][j] == 1 && !visited[i][j]) {
				area++;
				vec.push_back(DFS(i, j));
			}
		}
	}
	
	cout << area << endl;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

	return 0;
}