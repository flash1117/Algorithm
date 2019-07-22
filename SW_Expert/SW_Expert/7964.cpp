#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[300001];
bool visited[300001];
int N, D;

bool isBoundary(int x)
{
	if (x < 0 || x>299999) return false;
	return true;
}
int cntBuilding(int start) {

	int cnt=0;
	queue <pair<int, int>> q;
	q.push({ start,1 });
	visited[start] = true;

	while(!q.empty()) {

		int cur = q.front().first;
		cnt = q.front().second;
		q.pop();

		int next = cur + D;
		if (isBoundary(next)) {
			if (!visited[next]) {
				for (int i = cur; i < next; i++)
					visited[i] = true;
				q.push({ next, cnt + 1 });
				cout << next << "  ";
			}
			else
				return cnt;

		}		
	}

	return cnt;
}


int main() {

	memset(map, 0, sizeof(map));
	int T, ret =0, num=1;
	cin >> T;

	while (T--) {

		cin >> N >> D;
		for (int i = 0; i < N; i++) {
			cin >> map[i];
			if (map[i] == 1 && !visited[i]) {

				visited[i] = true;
				for (int j = 1; j <= D;j++) {
					if(isBoundary(i+j)) visited[i + j] = true;
					if(isBoundary(i-j)) visited[i - j] = true;
				}
			}
		}
		
		for (int i = 0; i < N; i++)
			cout << visited[i] << " ";

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				ret += cntBuilding(i);
				cout << "BFS µé¾î¿È";
			}
				
		}
		
		cout << "#" << num++<< " "<<ret << endl;
		memset(visited, false, sizeof(visited));
	}

	return 0;
}