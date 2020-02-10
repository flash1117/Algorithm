#include <iostream>

using namespace std;

int N, K;
int map[13][13];


int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


	return 0;
}