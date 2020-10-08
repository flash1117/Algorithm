#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {

	int r, c, s;
}Rotate;

int N, M, K;
int map[51][51];
vector<Rotate> rot;
int _order[7];

void print() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout <<  map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	return;
}


void rotateMap(int r, int c, int s) {


	for (int i = 1; i <= s; i++) {

		int leftTop = map[r - i][c - i];
		int leftBottom = map[r + i][c - i];
		int rightTop = map[r - i][c + i];
		int rightBottom = map[r + i][c + i];


		for (int j = r - i; j < r + i-1; j++) {
			map[j][c - i] = map[j + 1][c - i];

		}
		map[r + i - 1][c - i] = leftBottom;

		for (int j = c + i; j > c - i +1; j--) {
			map[r - i][j] = map[r - i][j - 1];
		}
		
		map[r - i][c - i + 1] = leftTop;

		for (int j = r + i; j > r - i + 1; j--) {
			map[j][c + i] = map[j - 1][c + i];
		}

		map[r - i + 1][c + i] = rightTop;

		for (int j = c - i; j < c + i - 1; j++) {
			map[r + i][j] = map[r + i][j + 1];
		}
		map[r + i][c + i - 1] = rightBottom;

	}

	return;
}

int getMinInMap() {

	const int MAX = 987654321;
	int ret = MAX;

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			
			sum += map[i][j];

		}

		ret = ret > sum ? sum : ret;
	}

	return ret;
}

int solve() {

	int minValue = 987654321;
	int _map[51][51];
	
	for (int i = 0; i < K; i++)
		_order[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			_map[i][j] = map[i][j];
		}
	}


	do {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				map[i][j] = _map[i][j];
			}
		}

		
		for (int i = 0; i < rot.size(); i++)
		{
			int index = _order[i];

			rotateMap(rot[index].r, rot[index].c, rot[index].s);
			//print();
		}

		int _min = getMinInMap();
		minValue = minValue > _min ? _min : minValue;

	} while (next_permutation(_order, _order+K));


	return minValue;
}



int main() {

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		Rotate input;
		cin >> input.r >> input.c >> input.s;
		rot.push_back(input);
	}

	cout << solve() << "\n";
	return 0;
}