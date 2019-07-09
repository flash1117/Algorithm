#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
bool visited[100001];
vector <int> relp[100001];
int start, cnt =0, node_cnt;

void DFS(int student) { // cycle search
	node_cnt++;
	visited[student] = true;

	int next = relp[student][0];

	if (next == student) {
		cnt++;
		return;
	}

	if(!visited[next])
		DFS(next);

	else if (visited[next]) { // 방문한 적이 있을 때

		if (next == start) {
			cnt += node_cnt;
		}
			
		return;
	}

}

int main() {

	int T, input;
	cin >> T;

	while (T--) {
		cnt = 0;
		memset(visited, false, sizeof(visited));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> input;
			relp[i].push_back(input);
			
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				start = i;
				node_cnt = 0;
				DFS(i);
				
			}		
		}
		
		for (int i = 1; i <= n; i++)
			relp[i].pop_back();

		cout <<n -cnt<< endl;
	}

	return 0;
}