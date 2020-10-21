#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int addMap[11][11];
vector<int> tree[11][11];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int extraMap[11][11];
int deadTree[11][11];
void init() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			extraMap[i][j] = 5;
			if (!tree[i][j].empty()) sort(tree[i][j].begin(), tree[i][j].end());
		}
	}
	return;
}

bool isBoundary(int x, int y) {

	if (x<1 || y<1 || x>N || y>N) return false;
	return true;
}

void spring() {

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
			int cnt = 0;
			for (int k = 0; k < tree[i][j].size(); k++) {

				if (tree[i][j][k] == 0) continue;
				else {
					if (tree[i][j][k] <= extraMap[i][j]) {
				
						extraMap[i][j] -= tree[i][j][k];
						tree[i][j][k]++;
					}
					else {
						cnt++;
						deadTree[i][j] += tree[i][j][k] / 2;
						tree[i][j][k] = 0;
					}
				}
			}
			for (int k = 0; k < cnt; k++)
				tree[i][j].pop_back();
		}
	}
}

void summer() {


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			extraMap[i][j] += deadTree[i][j];
			deadTree[i][j] = 0;
		}
	}
}

void fall() {

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {

			for (int k = 0; k < tree[i][j].size(); k++) {

				if (tree[i][j][k] != 0 && tree[i][j][k] % 5 == 0) {

					for (int index = 0; index < 8; index++) {
						int nextX = i + dx[index];
						int nextY = j + dy[index];

						if (isBoundary(nextX, nextY)) {
							tree[nextX][nextY].push_back(1);
						}
					}
				}
			}
		}
	}

}

void winter() {
	 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			extraMap[i][j] += addMap[i][j];
		}
	}

}

void print() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << extraMap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solve() {

	int liveTree =0;

	for (int i = 0; i < K; i++) {

		spring();
		summer();
		fall();
		winter();

	//	print();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] > 0) liveTree++;
			}
		}
	}

	return liveTree;
}



int main() {

	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			cin >> addMap[i][j];

		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);

	}

	init();
	cout << solve() << "\n";

	return 0;
}