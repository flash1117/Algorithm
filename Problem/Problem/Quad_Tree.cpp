#include <iostream>

using namespace std;

int N;
int map[64][64];

void solve(int lx, int ly, int rx, int ry, int maxValue) {

	if (rx - lx < 3 || ry - ly < 3) return;

	int maxb0=0, maxb1=0, maxb2=0, maxb3=0;

	for (int i = lx; i <= (rx - lx) / 2; i++) {
		for (int j = ly; j <= (ry - ly) / 2; j++) {
			maxb0 = maxb0 > map[i][j] ? maxb0 : map[i][j];
		}
	}

	for (int i = (rx - lx) / 2 + 1; i <= rx; i++) {
		for (int j = ly; j <= (ry - ly) / 2; j++) {
			maxb1 = maxb1 > map[i][j] ? maxb1 : map[i][j];
		}
	}

	for (int i = lx; i <= (rx - lx) / 2; i++) {
		for (int j = (ry - ly) / 2 + 1; j <= ry; j++) {

			maxb2 = maxb2 > map[i][j] ? maxb2 : map[i][j];
		}
	}

	for (int i = (rx - lx) / 2 + 1; i <= rx; i++) {
		for (int j = (ry - ly) / 2 + 1; j <= ry; j++) {
			maxb3 = maxb3 > map[i][j] ? maxb3 : map[i][j];
		}
	}
	
	int minMax = maxb1 > maxb0 ? maxb0 : maxb1;
	minMax = maxb2 > minMax ? minMax : maxb2;
	minMax = maxb3 > minMax ? minMax : maxb3;

	cout << lx << " " << ly << " " << rx << " " << ry << endl;

	solve(lx, ly, (rx - lx) / 2, (ry - ly) / 2, maxb0);
	solve((rx - lx) / 2 + 1, ly, rx, (ry - ly) / 2, maxb1); 
	solve(lx, (ry - ly) / 2 + 1, (rx - lx) / 2 , ry, maxb2); 
	solve((rx - lx) / 2 + 1, (ry - ly) / 2 + 1, rx, ry, maxb3); 
}

int main() {

	int caseNum = 1;
	cin >> N;
	while (N--) {

		int matSize, maxValue = 0;
		cin >> matSize;
		for (int i = 0; i < matSize; i++) {
			for (int j = 0; j < matSize; j++) {
				cin >> map[i][j];
				maxValue = maxValue > map[i][j] ? maxValue : map[i][j];
			}
		}



		cout << "#" << caseNum++ << " ";
		solve(0, 0, matSize - 1, matSize - 1, maxValue);
	}

	return 0;
}
