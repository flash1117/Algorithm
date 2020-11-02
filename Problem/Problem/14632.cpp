#include<iostream>
#include<cstring>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;
int N, M, K, H,W;
char map[1000][1000];
string stamp[500][500];
pair<int, int> cnt[500];


void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}cout << endl;
	}

}

bool isBoundary(int x, int y) {

	if (x <0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;

}

void makeMap(int stampNum, int x, int y) {

	for (int i = 0; i < cnt[stampNum - 1].first; i++) {
		for (int j = 0; j < cnt[stampNum - 1].second; j++) {

			if(isBoundary(x+i, y+j)) map[x + i][y + j] = stamp[stampNum - 1][i][j];

		}
	}

}

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> H >> W;
		cnt[i].first = H; cnt[i].second = W;
		for (int j = 0; j < H; j++)
			cin >> stamp[i][j];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = '.';

	int _command;
	cin >> _command;

	int x, y, stampNum;
	for (int i = 0; i < _command; i++) {
		cin >> stampNum >> x >> y;
		makeMap(stampNum, x, y);
	}
	print();
}