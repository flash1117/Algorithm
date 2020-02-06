#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int x, y, d1, d2;
}Bound;

int N;
int map[20][20];
vector <Bound> Area;

bool isBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return false;
	return true;
}

bool setBound(Bound input) {

	if (!isBoundary(input.x + input.d1, input.y - input.d1)) return false;
	else if (!isBoundary(input.x + input.d2, input.y + input.d2)) return false;

	return true;
}

void solve() {



}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					Bound input = { i,j,d1,d2 };
					bool isBound = setBound(input);
					if (isBound) Area.push_back(input);
				}
			}



		}
	}


	return 0;
}