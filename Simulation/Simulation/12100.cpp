#include <iostream>
#include <vector>

using namespace std;

typedef struct {

	int left, right, up, down;

}Direction;

int N;
int map[20][20];
int maxSum;

int getMax() {

	int _max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			_max = map[i][j] > _max ? map[i][j] : _max;

		}
	}

	return _max;
}

void solve(int cnt, Direction dir) {

	if (dir.down == 1) {
		
		for (int j = 0; j < N; j++)
		{
			int index = N - 1;
			vector<int> vec;
			for (int i = N - 1; i >= 0; i--) {

				if (map[i][j] != 0) {
					vec.push_back(map[i][j]);
					map[i][j] = 0;
				}

			}

			for (int i = 0; i < vec.size(); ) {

				if (i + 1 < vec.size() && vec[i] == vec[i + 1]) {
					map[index][j] = 2 * vec[i];
					i += 2;
					index--;
				}
				else {
					map[index][j] = vec[i];
					i++;
					index--;
				}

			}
			vec.clear();

		}
	}
	else if (dir.left == 1) {
		for (int i = 0; i < N; i++) {

			int index = 0;
			vector<int> vec;
			for (int j = 0; j<N; j++) {

				if (map[i][j] != 0) {
					vec.push_back(map[i][j]);
					map[i][j] = 0;
				}

			}

			for (int j = 0; j < vec.size(); ) {

				if (j + 1 < vec.size() && vec[j] == vec[j + 1]) {
					map[i][index] = 2 * vec[j];
					j += 2;
					index++;
				}
				else {
					map[i][index] = vec[j];
					j++;
					index++;
				}

			}
			vec.clear();

		}
	}
	else if (dir.right == 1) {

		for (int i = 0; i < N; i++) {

			int index = N-1;
			vector<int> vec;
			for (int j = N-1; j >=0; j--) {

				if (map[i][j] != 0) {
					vec.push_back(map[i][j]);
					map[i][j] = 0;
				}

			}

			for (int j = 0; j < vec.size(); ) {

				if (j + 1 < vec.size() && vec[j] == vec[j + 1]) {
					map[i][index] = 2 * vec[j];
					j += 2;
					index--;
				}
				else {
					map[i][index] = vec[j];
					j++;
					index--;
				}

			}
			vec.clear();

		}


	}
	else if (dir.up == 1) {

	for (int j = 0; j < N; j++)
	{
		int index = 0;
		vector<int> vec;
		for (int i = 0; i <N; i++) {

			if (map[i][j] != 0) {
				vec.push_back(map[i][j]);
				map[i][j] = 0;
			}

		}

		for (int i = 0; i < vec.size(); ) {

			if (i + 1 < vec.size() && vec[i] == vec[i + 1]) {
				map[index][j] = 2 * vec[i];
				i += 2;
				index++;
			}
			else {
				map[index][j] = vec[i];
				i++;
				index++;
			}

		}
		vec.clear();

	}


	}

	if (cnt == 5) {

		int _max = getMax();
		maxSum = maxSum > _max ? maxSum : _max;
		return;
	}

	int _map[20][20];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			_map[i][j] = map[i][j];
		}
	}


	solve(cnt + 1, { 1,0,0,0 }); // left
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = _map[i][j];
		}
	}
	

	solve(cnt + 1, { 0,1,0,0 }); // right
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = _map[i][j];
		}
	}


	solve(cnt + 1, { 0,0,1,0 }); // up
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = _map[i][j];
		}
	}
	solve(cnt + 1, { 0,0,0,1 }); // down
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = _map[i][j];
		}
	}
	return;
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> map[i][j];
		}
	}

	solve(0, { 0,0,0,0 });

	cout << maxSum << "\n";

	return 0;
}