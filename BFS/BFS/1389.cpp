#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[101];
vector <int> vec[101];
vector <int> ret[101];

typedef struct {

	int x, y;
}relp; // relationship

void BFS() {

	
}

int main() {

	cin >> N >> M;
	relp r;

	for (int i = 0; i < M; i++) {

		cin >> r.x >> r.y;
		vec[r.x].push_back(r.y);
		vec[r.y].push_back(r.x);

	}

	BFS();


	return 0;
}