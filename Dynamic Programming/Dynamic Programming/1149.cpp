#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[1001][3];

int DP(int color, int cnt ,int sum) {

	if (cnt == N) return sum;

	int min = 1001;
	if (sum == 0 && cnt ==0) {

		sum = map[cnt++][color];
		DP(color, cnt, sum);
	}
	else {

		for (int i = 0; i < 3; i++) {

			if (i == color) continue;
			else {
				if (min > map[cnt][i]) {
					min = map[cnt][i];
					color = i;
				}
			}
		}
		cnt++;
		sum += min;
		DP(color, cnt, sum);
	}
	
}

int main() {

	int ret = 1000001;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> map[i][0] >> map[i][1] >> map[i][2];

	for (int i = 0; i < 3; i++) {
		temp = DP(i, 0, 0);
		if (ret > temp) ret = temp;
	}
	
	cout << ret;

	return 0;
}