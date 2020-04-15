#include <iostream>
#include <vector>

using namespace std;

int A[100][100];
int r, c, k;


void rSort() { 

	for (int i = 0; i < 100; i++) {


		if (A[i][0] == 0) break;
	}


}

void cSort() {

	for (int i = 0; i < 100; i++) {
		if (A[0][i] == 0) break;
	}
}

void solve() {



}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}
	solve();

	return 0;
}