#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
pair<int,int> map[20][20]; // first = shark, second = delete time
int curSharkDir[401];
pair<int, int> sharkPos[401];
int sharkDirPriority[401][4][4];
vector<pair<int, int>> turn2OwnAreaPos;

// 가장 작은 번호를 가진 상어가 살아남는다.
// 상어는 자기가 있는 자리에 냄새를 뿌린다.
// 상어가 뿌린 냄새는 k번 이동하고 나면 사라진다.

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool isBoundary(int x, int y) {
	if (x <0 || y<0 || x>n - 1 || y>n - 1) return false;
	return true;
}


int isEmptyExist(int index) {
	/*
	cout << endl;
	cout << "index : " << index <<  " "<< curSharkDir[index]<<endl;
	for (int i = 0; i < 4; i++) {
		cout << sharkDirPriority[index][curSharkDir[index] - 1][i] << " ";
	}
	cout << endl;

	*/
	
	for (int i = 0; i < 4; i++) {
		int nextX = sharkPos[index].first + dx[sharkDirPriority[index][curSharkDir[index] - 1][i]-1];
		int nextY = sharkPos[index].second + dy[sharkDirPriority[index][curSharkDir[index] - 1][i]-1];

	//	if (index == 2 && nextX == 2 && nextY == 2) cout << "여기! " << map[nextX][nextY].first << " " << map[nextX][nextY].second;

		if (isBoundary(nextX, nextY) && map[nextX][nextY].first == 0 && map[nextX][nextY].second == 0) return sharkDirPriority[index][curSharkDir[index] - 1][i] - 1;
		else if (isBoundary(nextX, nextY) && map[nextX][nextY].first > 0 && map[nextX][nextY].second == k) {
			bool state = false;
			for (int j = 0; j < turn2OwnAreaPos.size(); j++) {
				if (nextX == turn2OwnAreaPos[j].first && nextY == turn2OwnAreaPos[j].second) {
					state = true;
					break;
				}
			}

			if (state) continue;

			return sharkDirPriority[index][curSharkDir[index] - 1][i] - 1;
		}
	}
	return -1;
}

void print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cout << map[i][j].first << " ";
		}
		cout << "\n";
	}
}

int solve() {
	int ret = 0;
	int sharkCnt = m;

	while (sharkCnt > 1) {
		
		if (ret > 1000) return -1;
		ret++;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (map[i][j].first > 0 && map[i][j].second > 0) map[i][j].second--;
				else if (map[i][j].second == 0 && map[i][j].first > 0) {
					map[i][j].first = 0;
				}
				
			}
		}

		print();
		for (int i = 1; i <= m; i++) {

			if (sharkPos[i].first == -1 && sharkPos[i].second == -1) continue;

			int emptyPos = isEmptyExist(i);
		//	cout << i << " " << emptyPos << endl;
			if (emptyPos == -1) {

				for (int j = 0; j < 4; j++) {
					int nextX = sharkPos[i].first + dx[sharkDirPriority[i][curSharkDir[i] - 1][j] - 1];
					int nextY = sharkPos[i].second + dy[sharkDirPriority[i][curSharkDir[i] - 1][j] - 1];

					if (map[nextX][nextY].first == i) {
						turn2OwnAreaPos.push_back(make_pair(nextX, nextY));
						map[nextX][nextY].second = k;
						curSharkDir[i] = sharkDirPriority[i][curSharkDir[i] - 1][j];
						sharkPos[i].first = nextX;
						sharkPos[i].second = nextY;
						break;
					}

				}


			}
			else {
				
				int nextX = sharkPos[i].first + dx[emptyPos];
				int nextY = sharkPos[i].second + dy[emptyPos];

				/*
				cout << "\n";
				cout << sharkPos[i].first << " , " << sharkPos[i].second << "\n";
				cout << nextX << " , " << nextY << " " << map[nextX][nextY].first << " " << map[nextX][nextY].second << "\n";
				*/
				
				if (map[nextX][nextY].first == 0) {

					map[nextX][nextY].first = i;
					map[nextX][nextY].second = k;
					curSharkDir[i] = emptyPos + 1;
					sharkPos[i].first = nextX;
					sharkPos[i].second = nextY;


				}
				else {
					sharkCnt--;
					if (map[nextX][nextY].first < i) {
						sharkPos[i].first = -1;
						sharkPos[i].second = -1;

					}
					else {

						sharkPos[map[nextX][nextY].first].first = -1;
						sharkPos[map[nextX][nextY].first].second = -1;

						map[nextX][nextY].first = i;
						curSharkDir[i] = emptyPos + 1;
						sharkPos[i].first = nextX;
						sharkPos[i].second = nextY;

					}

				}
			}
		}
		turn2OwnAreaPos.clear();
	}

	return ret;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j].first;

			if (map[i][j].first > 0) {
				map[i][j].second = k;
				sharkPos[map[i][j].first].first = i;
				sharkPos[map[i][j].first].second = j;
			}
			
		}
	}

	for (int i = 1; i <= m; i++)
		cin >> curSharkDir[i];


	for (int i = 0; i < m; i++) {

		for (int j = 0; j < 4; j++) {
			for (int x = 0; x < 4; x++) {
				cin >> sharkDirPriority[i + 1][j][x];
			}

		}

	}

	cout << solve() << "\n";


	return 0;
}