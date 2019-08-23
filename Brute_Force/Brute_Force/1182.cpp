#include <iostream>
#include <vector>

using namespace std;

#define Endl "\n"

vector <int> vec;
int N, S, cnt, sum;
int ary[21];

void DFS(int depth , int dst) {

	sum += vec[depth];

	if (depth >= N) return;

	if (sum == S)
		cnt++;


	DFS(depth + 1, sum - vec[depth]);

	DFS(depth + 1, sum);
}

int main() {

	cin >> N >> S;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}

	DFS(0,0);

	cout << cnt;

	return 0;
}