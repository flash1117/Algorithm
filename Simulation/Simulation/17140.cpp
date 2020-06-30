#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;
int map[101][101];
int rLen, cLen;
pair<int, int> arrayCnt[101];


void init() {

	for (int i = 1; i < 101; i++) {
		arrayCnt[i] = { i,0 };
	}

}

bool compare(pair<int,int> a, pair<int,int> b) {

	return a.second < b.second;


}

void print() {

	for (int i = 1; i < 101; i++) {
		cout << arrayCnt[i].first << " " << arrayCnt[i].second << "\n";
	}
}

int solve() {

	int ret = 0;

	if (map[r][c] == k) return ret;
	else if (ret > 100) return -1;

	if (rLen >= cLen) // Çà¿¬»ê
	{
		for (int i = 0; i < rLen; i++) {

			for (int j = 0; j < c; j++) {
				if (map[i][j] == 0) break;
				else {
					arrayCnt[map[i][j]].second++;
				}

			}

			sort(arrayCnt+1, arrayCnt + 100, compare);
			print();
			init();
		}

	}
	else {

	}

	return 0;
}


int main() {
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			cin >> map[i][j];
		}
	}
	rLen = r;
	cLen = c;
	init();
	cout << solve() << "\n";
	
	return 0;
}