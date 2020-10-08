#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;
int map[101][101];
int rowLen = 3, colLen = 3;
int MAX_TIME = 100;


void print() {

	cout << endl;
	for (int i = 0; i < rowLen; i++) {

		for (int j = 0; j < colLen; j++) {

			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	return;
}

void rowMove() {

	int indexCnt[101];
	colLen = 0;
	vector<int> q;

	for (int i = 0; i < 100; i++) {

		
		int maxCnt = 0;
		
		for (int j = 1; j <= 100; j++) indexCnt[j] = 0;

		for (int j = 0; j < 100; j++) {

			if (map[i][j] == 0) continue;

			int cur = map[i][j];
			indexCnt[cur]++;
			maxCnt = maxCnt > indexCnt[cur] ? maxCnt : indexCnt[cur];
		}

		for (int j = 1; j <= maxCnt; j++) {

			for (int k = 1; k <= 100; k++) {
				if (indexCnt[k] == j) {
					q.push_back(k);
					q.push_back(j);
				}
			}

		}

		
		if (q.size() >= 100) {
			colLen = 100;

			for (int j = 0; j < 100; j++) {

				map[i][j] = q[j];
			}


		}
		else {

			colLen = q.size() > colLen ? q.size() : colLen;
			for (int j = 0; j < q.size(); j++) {

				map[i][j] = q[j];
			}

			for (int j = q.size(); j < 100; j++)
				map[i][j] = 0;
			
		}


		q.clear();

	}


	return;
}


void colMove() {

	int indexCnt[101];
	rowLen = 0;
	vector<int> q;

	for (int i = 0; i < 100; i++) {

		int maxCnt = 0;

		for (int j = 1; j <= 100; j++) indexCnt[j] = 0;

		for (int j = 0; j < 100; j++) {

			if (map[j][i] == 0) continue;

			int cur = map[j][i];
			indexCnt[cur]++;
			maxCnt = maxCnt > indexCnt[cur] ? maxCnt : indexCnt[cur];
		}

		for (int j = 1; j <= maxCnt; j++) {

			for (int k = 1; k <= 100; k++) {
				if (indexCnt[k] == j) {
					q.push_back(k);
					q.push_back(j);
				}
			}

		}

		
		if (q.size() >= 100) {
			rowLen = 100;
			for (int j = 0; j < 100; j++) {

				map[j][i] = q[j];
			}


		}
		else {
			rowLen = q.size() > rowLen ? q.size() : rowLen;
			for (int j = 0; j < q.size(); j++) {

				map[j][i] = q[j];
			}

			
				for (int j = q.size(); j < 100; j++)
					map[j][i] = 0;
			
		}
	
		q.clear();

	}

	return;
}

int solve() {

	if (map[r - 1][c - 1] == k) return 0;

	while (MAX_TIME--) {

	//	print();


		if (rowLen >= colLen) {
			rowMove();
		}
		else {
			colMove();
		
		}
		
		if (map[r - 1][c - 1] == k) return 100 - MAX_TIME;
		
	}

	return -1;
}


int main() {

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	cout << solve() << "\n";

	return 0;
}