#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector <int> vec[101];
int ret[101];

int DFS(int src, int dst, int cnt) {

	if (src == dst) {
		return cnt;

	}


}

int main() {
	int input1, input2;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;
		vec[input1].push_back(input2);

	}



	return 0;
}