#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int map[51][51];
bool visited[51][51];

vector <pair<int, int>> vec;


void BFS() {




}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				vec.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < vec.size(); i++) {


	}


	return 0;
}