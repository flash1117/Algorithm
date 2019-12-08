#include <iostream>

using namespace std;

typedef struct {
	int picture1, picture2, cnt;
}Picture;

int N;
char map[50][5][7];

void solve() {

	Picture p = { 50, 51,36 }; // people number & different char count

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int cnt = 0;

			for (int v = 0; v < 5; v++) {
				for (int h = 0; h < 7; h++) {
					if (map[i][v][h] != map[j][v][h]) cnt++;
				}
			}

			if (p.cnt > cnt) {
				p.picture1 = i+1;
				p.picture2 = j+1;
				p.cnt = cnt;
			}
		}
	}
	cout << p.picture1 << " " << p.picture2 << "\n";
}

int main() {

	cin >> N;

	for (int st = 0; st < N; st++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 7; j++) {
				cin >> map[st][i][j];
			}
		}
	}
	
	solve();

	return 0;
}