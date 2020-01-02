#include <iostream>

using namespace std;

int N, M, maxNum=0;
int map[500][500];

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>M - 1) return false;
	return true;
}

int sq(int ptX, int ptY) {

	if (isBoundary(ptX + 1, ptY + 1)) 
		return map[ptX][ptY] + map[ptX][ptY + 1] + map[ptX + 1][ptY] + map[ptX + 1][ptY + 1];
	return -1;
}

int st(int ptX, int ptY) {

	int sum1=0, sum2 = 0;
	if (isBoundary(ptX + 3, ptY+3)) {

		for (int i = 0; i < 4; i++)
			sum1 += map[ptX + i][ptY];

		for (int i = 0; i < 4; i++)
			sum2 += map[ptX][ptY + i];

		sum1 = sum1 > sum2 ? sum1 : sum2;
		return sum1;
	}
	else if (isBoundary(ptX + 3, ptY)) {
		for (int i = 0; i < 4; i++)
			sum1 += map[ptX + i][ptY];
		return sum1;
	}
	else if (isBoundary(ptX, ptY + 3)) {
		for (int i = 0; i < 4; i++)
			sum2 += map[ptX][ptY + i];
		return sum2;
	}

	return -1;

}

int F1(int ptX, int ptY) { // fiqure 1

	int sum1 = 0, sum2 = 0, ret = 0;

	if (isBoundary(ptX + 2, ptY + 2)) {

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX][ptY+i];
			sum2 += map[ptX + 1][ptY+i];
			
		}
		
		if (map[ptX + 1][ptY] > map[ptX + 1][ptY + 2]) sum1 += map[ptX + 1][ptY];
		else sum1 += map[ptX + 1][ptY + 2];

		if (map[ptX][ptY] > map[ptX][ptY + 2]) sum2 += map[ptX][ptY];
		else sum2 += map[ptX][ptY + 2];

//		if (ptX == 2 && ptY == 2) cout << sum1 << " " << sum2 << endl;
		ret = sum1 > sum2 ? sum1 : sum2;
		
		sum1 = 0; sum2 = 0;

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX+i][ptY];
			sum2 += map[ptX+i][ptY + 1];
		}

		if (map[ptX][ptY] > map[ptX + 2][ptY]) sum2 += map[ptX][ptY];
		else sum2 += map[ptX + 2][ptY];

		if (map[ptX][ptY + 1] > map[ptX + 2][ptY + 1]) sum1 += map[ptX][ptY + 1];
		else sum1 += map[ptX+2][ptY + 1];


//		if (ptX == 2 && ptY == 2) cout << sum1 << " " << sum2 << endl;
		ret = ret > sum1 ? ret : sum1;
		ret = ret > sum2 ? ret : sum2;
		return ret;

	}
	else if (isBoundary(ptX + 1, ptY + 2)) {
		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX][ptY+i];
			sum2 += map[ptX + 1][ptY+i];
		}

		if (map[ptX + 1][ptY] > map[ptX + 1][ptY + 2]) sum1 += map[ptX + 1][ptY];
		else sum1 += map[ptX + 1][ptY + 2];

		if (map[ptX][ptY] > map[ptX][ptY + 2]) sum2 += map[ptX][ptY];
		else sum2 += map[ptX][ptY + 2];

		ret = sum1 > sum2 ? sum1 : sum2;
		return ret;
	}
	else if (isBoundary(ptX + 2, ptY + 1)) {

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX+i][ptY];
			sum2 += map[ptX+i][ptY+1];
		}

		if (map[ptX][ptY] > map[ptX + 2][ptY]) sum2 += map[ptX][ptY];
		else sum2 += map[ptX + 2][ptY];

		if (map[ptX][ptY + 1] > map[ptX + 2][ptY + 1]) sum1 += map[ptX][ptY + 1];
		else sum1 += map[ptX+2][ptY + 1];

		ret = sum1 > sum2 ? sum1 : sum2;
		return ret;

	}
	
	return -1;
}

int F2(int ptX , int ptY) {

	int sum1 = 0, sum2 = 0, ret = -1;

	if (isBoundary(ptX + 2, ptY + 2)) {

		sum1 = map[ptX][ptY] + map[ptX + 1][ptY] + map[ptX + 1][ptY + 1] + map[ptX + 2][ptY + 1];
		sum2 = map[ptX][ptY + 1] + map[ptX + 1][ptY + 1] + map[ptX + 1][ptY] + map[ptX + 2][ptY];

		ret = sum1 > sum2 ? sum1 : sum2;

		sum1 = map[ptX + 1][ptY] + map[ptX + 1][ptY + 1] + map[ptX][ptY + 1] + map[ptX][ptY + 2];
		sum2 = map[ptX][ptY] + map[ptX][ptY + 1] + map[ptX + 1][ptY + 1] + map[ptX + 1][ptY + 2];

		sum1 = sum1 > sum2 ? sum1 : sum2;
		ret = ret > sum1 ? ret : sum1;
		return ret;

	}
	else if (isBoundary(ptX + 1, ptY + 2)) {

		sum1 = map[ptX + 1][ptY] + map[ptX + 1][ptY + 1] + map[ptX][ptY + 1] + map[ptX][ptY + 2];
		sum2 = map[ptX][ptY] + map[ptX][ptY + 1] + map[ptX + 1][ptY + 1] + map[ptX + 1][ptY + 2];

		ret = sum1 > sum2 ? sum1 : sum2;
	
	}
	else if (isBoundary(ptX + 2, ptY + 1)) {

		sum1 = map[ptX][ptY] + map[ptX + 1][ptY] + map[ptX + 1][ptY + 1] + map[ptX + 2][ptY + 1];
		sum2 = map[ptX][ptY + 1] + map[ptX + 1][ptY + 1] + map[ptX + 1][ptY] + map[ptX + 2][ptY];

		ret = sum1 > sum2 ? sum1 : sum2;
	}

	return ret;

}

int F3(int ptX, int ptY) {

	int sum1 = 0, sum2 = 0, ret = -1;

	if (isBoundary(ptX + 2, ptY + 2)) {

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX][ptY+i];
			sum2 += map[ptX + 1][ptY+i];
		}
		sum1 += map[ptX + 1][ptY + 1];
		sum2 += map[ptX][ptY + 1];

		ret = sum1 > sum2 ? sum1 : sum2;

		sum1 = 0; sum2 = 0;

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX+i][ptY];
			sum2 += map[ptX+i][ptY + 1];
		}
		sum1 += map[ptX + 1][ptY + 1];
		sum2 += map[ptX + 1][ptY];

		ret = ret > sum1 ? ret : sum1;
		ret = ret > sum2 ? ret : sum2;

	}
	else if (isBoundary(ptX + 1, ptY + 2)) {

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX][ptY+i];
			sum2 += map[ptX + 1][ptY+i];
		}
		sum1 += map[ptX + 1][ptY + 1];
		sum2 += map[ptX][ptY + 1];

		ret = sum1 > sum2 ? sum1 : sum2;

	}
	else if (isBoundary(ptX + 2, ptY + 1)) {

		for (int i = 0; i < 3; i++) {
			sum1 += map[ptX+i][ptY];
			sum2 += map[ptX+i][ptY + 1];
		}
		sum1 += map[ptX + 1][ptY + 1];
		sum2 += map[ptX + 1][ptY];

		ret = ret > sum1 ? ret : sum1;
		ret = ret > sum2 ? ret : sum2;
	}

	return ret;

}


void solve() {
	
	int ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			ret = sq(i, j);
			maxNum = maxNum > ret ? maxNum : ret;
			ret = st(i, j);
			maxNum = maxNum > ret ? maxNum : ret;
			ret = F1(i, j);
			maxNum = maxNum > ret ? maxNum : ret;
			ret = F2(i, j);
			maxNum = maxNum > ret ? maxNum : ret;
			ret = F3(i, j);
			maxNum = maxNum > ret ? maxNum : ret;
			
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	solve();
	cout << maxNum << "\n";
	return 0;
}