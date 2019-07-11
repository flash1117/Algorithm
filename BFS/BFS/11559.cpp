#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

char map[12][6];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isBoundary(int x, int y) {
	if (x < 0 || y < 0 || x>11 || y>5) return false;
	return true;

}

void BFS() {

	queue <pair<int, int>>q;
	

}

void print() {

	for (int i = 0; i < 12; i++) {

		for (int j = 0; j < 6; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}
int main() {


	for (int i = 0; i < 12; i++) {

		for (int j = 0; j < 6; j++) {

			cin >> map[12-i][j];
		}
	}

	return 0;
}