#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

/*
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�,
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000),
Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����.
� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

ù° �ٿ� DFS�� ������ �����,
�� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.
*/

#define MAX 1001

bool visit[MAX];
vector <int> adjacent[MAX];
queue <int> Q;

void DFS(int start) {

	visit[start] = true;
	cout << start<<" ";
	for (int y : adjacent[start]) {
		if (!visit[y]) {
			DFS(y);
		}
	}

}

void BFS(int start) {

	Q.push(start);
	visit[start] = true;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		cout << x<<" ";
		for (int y : adjacent[x]) {
			if (!visit[y]) {
				Q.push(y);
				visit[y] = true;

			}
		}
	}
}

int main() {

	int N=0 , M=0 , V=0;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		adjacent[s].push_back(e);
		adjacent[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(adjacent[i].begin(), adjacent[i].end());
	}

	DFS(V);
	puts("");
	memset(visit, 0, sizeof(visit));
	BFS(V);
	puts("");

	return 0;
}