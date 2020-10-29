#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int dst, cost;
}Pos;

int V, E, K;
int visited[20001];
vector<Pos> vec[20001];
vector<int> minDistVector;


bool isExist(int src, int dst, int cost) {

	bool isChange = false;

	for (int i = 0; i < vec[src].size(); i++) {


		if (vec[src][i].dst == dst && vec[src][i].cost > cost) {
			vec[src][i].cost = cost;
			isChange = true;
			break;
		}
		else if (vec[src][i].dst == dst && vec[src][i].cost <= cost) {
			return true;
		}
	}

	return false;
}

void initVisited() {

	for (int i = 1; i <= V; i++)
		visited[i] = -1;

}

int getMinDist(int dst) {

	vector<int> distCost;
	initVisited();
	queue<pair<int, int>> q;

	for (int i = 0; i < vec[1].size(); i++) {

		q.push(make_pair(vec[1][i].dst, vec[1][i].cost));
		visited[vec[1][i].dst] = vec[1][i].cost;
	}

	while (!q.empty()) {

		int cur = q.front().first;
		int costSum = q.front().second;

		q.pop();

		if (cur == dst) {

			distCost.push_back(costSum);
		}

		for (int i = 0; i < vec[cur].size(); i++) {

			int next = vec[cur][i].dst;
			int _sum = costSum + vec[cur][i].cost;
			if (visited[next] == -1) {

				q.push({ next, _sum });
				visited[next] = _sum;
			}
			else if (visited[next] != -1 && visited[next] > _sum) {
				q.push({ next, _sum });
				visited[next] = _sum;

			}

		}

	}

	if(distCost.empty()) return -1;
	else {
		sort(distCost.begin(), distCost.end());
		return distCost.front();

	}
}


void printResult() {

	for (int i = 0; i < minDistVector.size(); i++) {
		
		if (minDistVector[i] != -1) {
			cout << minDistVector[i] << "\n";
		}
		else cout << "INF\n";

	}

	return;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {

		int u, v, w;
		cin >> u >> v >> w;

		bool _exist = isExist(u, v, w);
		if (!_exist) {
			vec[u].push_back({ v,w });
		}

	}

	minDistVector.push_back(0);

	for (int i = 2; i <= V; i++) {

		int minDistance = getMinDist(i);
		minDistVector.push_back(minDistance);
	}

	printResult();

	return 0;
}