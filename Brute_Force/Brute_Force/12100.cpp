#include <iostream>

using namespace std;

int N, maxNode;
int map[20][20], copyMap[20][20][5];
char order[4] = { 'U', 'D', 'R', 'L' };

void move(char od, int index) { 

	if (od == 'U') {

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N - 1; i++) {

				if (copyMap[i][j][index] == 0) {

					for (int k = i; k < N-1; k++) {
						copyMap[k][j][index] = copyMap[k+1][j][index];
						if (k == N - 2) copyMap[k+1][j][index] = 0;
					}
				}
			}
		}
	}
	else if (od == 'D') {

		for (int j = 0; j < N; j++) {

			for (int i = N - 1; i >= 0; i--) {

				if (copyMap[i][j][index] == 0) {

					for (int k = i; k > 0; k--) {
						copyMap[k][j][index] = copyMap[k-1][j][index];
						if (k == 1) copyMap[k-1][j][index] = 0;
					}
				}
			}
		}
	}
	else if (od == 'R') {

		for (int i = 0; i < N; i++) {

			for (int j = N - 1; j > 0; j--) {

				if (copyMap[i][j][index] == 0) {

					for (int k = j; k > 0; k--) {
						copyMap[i][k][index] = copyMap[i][k-1][index];
						if (k == 1) copyMap[i][k][index] = 0;
					}
				}
			}
		}

	}
	else if (od == 'L') {

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N-1; j++) {

				if (copyMap[i][j][index] == 0) {

					for (int k = j; k < N-1; k++) {
						copyMap[i][k][index] = copyMap[i][k+1][index];
						if (k == N-2) copyMap[i][k+1][index] = 0;
					}
				}
			}
		}
	}

}

void compose(char od , int index) {

	if (od == 'U') {

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N - 1; i++) {

				if (copyMap[i][j][index] != 0) {

					for (int k = i + 1; k < N; k++) {
						
						if (copyMap[k][j][index] != 0 && copyMap[k][j][index] == copyMap[i][j][index]) {

							copyMap[i][j][index] *= 2;
							copyMap[k][j][index] = 0;
						}
						else if (copyMap[k][j][index] == 0) continue;
						break;
					}
				}
			}
		}

	}
	else if (od == 'D') {

		for (int j = 0; j < N; j++) {
			for (int i = N-1; i > 0; i--) {

				if (copyMap[i][j][index] != 0) {

					for (int k = i - 1; k >= 0; k--) {

						if (copyMap[k][j][index] != 0 && copyMap[k][j][index] == copyMap[i][j][index]) {

							copyMap[i][j][index] *= 2;
							copyMap[k][j][index] = 0;
						}
						else if (copyMap[k][j][index] == 0) continue;
						break;
					}
				}
			}
		}

	}
	else if (od == 'R') {

		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j > 0; j--) {

				if (copyMap[i][j][index] != 0) {

					for (int k = j - 1; k >= 0; k--) {

						if (copyMap[i][k][index] != 0 && copyMap[i][k][index] == copyMap[i][j][index]) {

							copyMap[i][j][index] *= 2;
							copyMap[i][k][index] = 0;
						}
						else if (copyMap[i][k][index] == 0) continue;
						break;
					}
				}

			}
		}

	}
	else if (od == 'L') {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {

				if (copyMap[i][j][index] != 0) {

					for (int k = j+1; k < N; k++) {

						if (copyMap[i][k][index] != 0 && copyMap[i][k][index] == copyMap[i][j][index]) {

							copyMap[i][j][index] *= 2;
							copyMap[i][k][index] = 0;
						}
						else if (copyMap[i][k][index] == 0) continue;
						break;
					}
				}

			}
		}
	}
}
void initArray(int index) {

	if (index == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				copyMap[i][j][0] = map[i][j];
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			copyMap[i][j][index] = copyMap[i][j][index - 1];
	}

	return;
}

void findMax() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxNode = maxNode > copyMap[i][j][4] ? maxNode : copyMap[i][j][4];
		}
	}

}

void print(int k) {

	cout << endl;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << copyMap[i][j][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve() {

	for (int i = 0; i < 4; i++) {

		initArray(0);
		compose(order[i], 0);
		move(order[i],0);

		for (int j = 0; j < 4; j++) {

			initArray(1);
			compose(order[j], 1);
			move(order[j],1);

			for (int k = 0; k < 4; k++) {

				initArray(2);
				compose(order[k], 2);
				move(order[k],2);
				print(2);


				for (int l = 0; l < 4; l++) {

					initArray(3);
					compose(order[l], 3);
					move(order[l],3);

					for (int m = 0; m < 4; m++) {

						initArray(4);
						compose(order[m], 4);
						move(order[m],4);
						if(m == 0 || m == 2) findMax();
						
					}
				}
			}
		}

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	solve();
	cout << maxNode << "\n";

	return 0;
}