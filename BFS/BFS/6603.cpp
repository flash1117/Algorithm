#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int k=1;
int s[50];
int visited[50];

void BFS() {

	queue <int> q;
	q.push(s[0]);

	while (!q.empty()) {
		

		for (int i = 0; i < k; i++) {


		}


	}



}

int main() {

	while (k != 0) {
		memset(s, 0, sizeof(s));
		memset(visited, 0, sizeof(visited));

		cin >> k;
		for (int i = 0; i < k; i++) {
			
			cin >> s[i];

		}
		BFS();
	}
 
	return 0;
}