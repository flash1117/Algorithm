#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector <int> vec[100001];

typedef struct {

	int src, cnt;
}pos;

void BFS() {

	queue <pos> q;
	for (int i = 0; i < N; i++) {

		if (!vec[i].empty()) 
			q.push({i,0});

	}
	
	while (!q.empty()) {

		int cur = q.front().src;
		int ccnt = q.front().cnt;

		q.pop();

		for (int i = 0; i < vec[cur].size(); i++) {

			int next = vec[cur][i];
			q.push({})

		}



	}


}

int main() {

	int input1, input2;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> input1 >> input2;
		vec[input1].push_back(input2);

	}

	BFS();
	return 0;
}