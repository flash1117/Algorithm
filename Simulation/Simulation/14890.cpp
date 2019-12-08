#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, L;
int map[101][101];
bool visited[101][101];

void initArray() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

bool verCompare(int index, int pivot) {

	int left = 0, right = 0;

	if (map[index][pivot] - map[index][pivot - 1] == 1 && pivot > 0) { // left

		for (int i = pivot - 1; i >= 0; i--) {
			
			if (!visited[index][i] && map[index][i] == map[index][pivot] - 1) {
				left++;
			}

			if (left == L && i == pivot - L) {
				for (int j = pivot - 1; j >= i; j--)
					visited[index][j] = true;
				return true;
			}
		}

	}
	if (map[index][pivot] - map[index][pivot + 1] == 1 && pivot < N-1) // right 
	{
		for (int i = pivot + 1; i <= N-1; i++) {

			if (!visited[index][i] && map[index][i] == map[index][pivot] - 1) {
				right++;
			}

			if (right == L && i == pivot + L) {
				for (int j = pivot + 1; j <= i; j++)
					visited[index][j] = true;
				return true;
			}
		}

	}
	return false;
}

bool horCompare(int index, int pivot) {

	int left = 0, right = 0;

	if (map[pivot][index] - map[pivot-1][index] == 1 && pivot > 0) { // left

		for (int i = pivot - 1; i >= 0; i--) {

			if (!visited[i][index] && map[i][index] == map[pivot][index] - 1) {
				left++;
			}

			if (left == L && i == pivot - L) {
				for (int j = pivot - 1; j >= i; j--)
					visited[j][index] = true;
				return true;
			}
		}

	}
	if (map[pivot][index] - map[pivot+1][index] == 1 && pivot < N-1) // right 
	{
		for (int i = pivot + 1; i <= N - 1; i++) {

			if (!visited[i][index] && map[i][index] == map[pivot][index] - 1) {
				right++;
			}

			if (right == L && i == pivot + L) {
				for (int j = pivot + 1; j <= i; j++)
					visited[j][index] = true;
				return true;
			}
		}

	}
	return false;
}

int solve() {

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {

			if (abs(map[i][j] - map[i][j + 1]) > 1) break;
			else {
				if (map[i][j] == map[i][j + 1]);
				else {
					if (verCompare(i, (map[i][j] > map[i][j + 1]) ? j : j + 1));
					else break;
				}
			}
			
			if (j == N - 2) {
				ret++;
			}
		}
	}

	initArray();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {

			if (abs(map[j][i] - map[j + 1][i]) > 1) break;
			else {
				if (map[j][i] == map[j + 1][i]);
				else {
					if (horCompare(i, map[j][i] > map[j + 1][i] ? j : j + 1));
					else break;
				}
			}
			if (j == N - 2) ret++;
		}
	}
	return ret;
}

int main() {

	cin >> N >> L;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
		
	cout << solve() << "\n";
	return 0;
}