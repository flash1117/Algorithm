#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int x, y, dir;
}pos;

int N, K;
int map[13][13];
vector <pos> info;

int main() {
	pos input;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> input.x >> input.y >> input.dir;
		info.push_back(input);
	}

	return 0;
}