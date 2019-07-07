#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
bool visited[1001];
vector <int> vec[1001];
int area = 0;

void DFS(int pt) {

	visited[pt] = true;

	for (int i = 0; i<vec[pt].size(); i++) {

		if(!visited[vec[pt][i]])
			DFS(vec[pt][i]);
	}

}


int main() {

	memset(visited, false, sizeof(visited));
	int u, v;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);

	}

	for (int i = 1; i <= N; i++) {

		if (!visited[i]) {
			DFS(i);
			area++;
		}
			
	}

	cout << area;
	return 0;
}