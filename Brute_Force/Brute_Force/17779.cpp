#include <iostream>

using namespace std;

int N;
int map[21][21];
int pick[3];
int visited[21][21];
const int INF = 987654321;

bool isBoundary(int x, int y) {

	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

pair<int, int> getMinMaxPair(int sum1, int sum2, int sum3, int sum4, int sum5) {

	int _min = sum1, _max = sum1;

	if (_min > sum2) _min = sum2;
	if (_min > sum3) _min = sum3;
	if (_min > sum4) _min = sum4;
	if (_min > sum5) _min = sum5;

	if (_max < sum2) _max = sum2;
	if (_max < sum3) _max = sum3;
	if (_max < sum4) _max = sum4;
	if (_max < sum5) _max = sum5;

	return make_pair(_min, _max);

}

void printVisited() {

	for (int i = 1; i = N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void visitedInit() {

	for (int i = 1; i = N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = 0;
		}
	}
	return;
}


int peopleCntDist(int x, int y, int d1, int d2) {

//	visitedInit();

	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {


			if (i < x + d1 && j <= y && !(i>=x && j >= y-(i-x))) {
				sum1 += map[i][j];
			//	visited[i][j] = 1;
			}
			else if (i <= x + d2 && y < j && j <= N && !(i>=x && j <= y + (i-x))) {
				sum2 += map[i][j];
			//	visited[i][j] = 2;
			}
			else if (x + d1 <= i && i <= N && j < y - d1 + d2 && !(i>=x+d1 && j>= (y-d1+d2)-(x+d1+d2-i) )) {
				sum3 += map[i][j];
			//	visited[i][j] = 3;
			}
			else if (x + d2 < i && y - d1 + d2 <= j && !(i >= x + d1 && j <= (y - d1 + d2) + (x + d1 + d2 - i))) {
				sum4 += map[i][j];
			//	visited[i][j] = 4;
			}
			else {
				sum5 += map[i][j];
			//	visited[i][j] = 5;
			}
		}
	}
	
	if (sum1 == 0 || sum2 == 0 || sum3 == 0 || sum4 == 0 || sum5 == 0) return -1;

//	cout << "\n";
//	cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << " " << sum5 << "\n";
//	cout << "x : " << x << " y : " << y << " d1 : " << d1 << " d2 : " << d2 << "\n";
	//printVisited();
//	cout << "\n";

	pair<int, int> p = getMinMaxPair(sum1, sum2, sum3, sum4, sum5);

	return p.second - p.first;
}

int getMinByBoundSet(int x, int y) {
	int _min = INF;

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			int d1 = i;
			int d2 = j;
			if (x + d1 + d2 <= N && 1 <= y - d1 && y - d1 < y && y < y + d2 && y + d2 <= N) {

				int ret = peopleCntDist(x, y, d1, d2);
				if (ret != -1) {
					_min = _min > ret ? ret : _min;
					

				}
			}
			else break;

		}
	}

	return _min;
}



int main() {
	
	int minDist = INF;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int ret = getMinByBoundSet(i, j);
			minDist = minDist > ret ? ret : minDist;
		}
	}

	cout << minDist << "\n";

	return 0;
}