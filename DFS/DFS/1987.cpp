#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int R, C;
char map[21][21];
bool visited[21][21];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector <int> vec;

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>R - 1 || y> C - 1) return false;
	return true;
}

bool isSame(int x, int y) {

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; i++) {

			if (visited[i][j] && map[i][j] == map[x][y])
				return true;

		}
	}

	return false;
}

void DFS(int x, int y, int cnt) {

	visited[x][y] = true;

	if (!isBoundary(x, y)) return;
	else {

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (isSame(nextX, nextY)) {
				vec.push_back(cnt);
				return;
			}
				
			else if(isBoundary(nextX, nextY) && visited[nextX][nextY] == false){
				cout << nextX <<" , "<< nextY << endl;
				DFS(nextX, nextY, cnt + 1);

			}
		}
	}
}



int main() {
	string temp;
	memset(visited, false, sizeof(visited));

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> temp;
		for (int j = 0; j < C; j++) {
			map[i][j] = temp[j] - '0';
		}
	}

	DFS(0, 0, 1);


	/*for (int i = 0; i < vec.size(); i++) {

		cout << vec[i] << " ";
	}*/
	
	return 0;
}