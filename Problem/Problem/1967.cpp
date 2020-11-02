#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> tree[10001];
pair<int,int> saveParentNode[10001];
int maxTreeDiameter;
int nodeMaxWeight[10001];

void travelTree(int startNode) {

	bool visited[10001];
	for (int i = 1; i <= N; i++) visited[i] = false;

	queue<pair<int, int>> q;
	visited[startNode] = true;
	q.push(make_pair(saveParentNode[startNode].first, saveParentNode[startNode].second));
	visited[saveParentNode[startNode].first] = true;
//	cout << "\n";
//	cout << startNode << "\n";
	while (!q.empty()) {

		int curNode = q.front().first;
		int weightSum = q.front().second;

		q.pop();

		maxTreeDiameter = maxTreeDiameter > weightSum ? maxTreeDiameter : weightSum;

//		cout << curNode << " " << weightSum << "\n";


		for (int i = 0; i < tree[curNode].size(); i++) {

			int nextNode = tree[curNode][i].first;
			int nextWeight = tree[curNode][i].second;

			if (!visited[nextNode]) {

				q.push(make_pair(nextNode, weightSum + nextWeight));
				visited[nextNode] = true;
			}


		}

		int parentNode = saveParentNode[curNode].first;
		int nWeight = saveParentNode[curNode].second;

		if (parentNode != 0 && !visited[parentNode]) {
			q.push(make_pair(parentNode, weightSum + nWeight));
			visited[parentNode] = true;
		}



	}


}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N;
	for (int i = 0; i < N - 1; i++) {

		int parentNode, childNode, weight;

		cin >> parentNode >> childNode >> weight;

		tree[parentNode].push_back(make_pair(childNode, weight));
		saveParentNode[childNode].first = parentNode;
		saveParentNode[childNode].second = weight;

		nodeMaxWeight[parentNode] = nodeMaxWeight[parentNode] > weight ? nodeMaxWeight[parentNode] : weight;
	}

	

	for (int i = 1; i <= N; i++) {

		if (tree[i].empty()) {

			int pNode = saveParentNode[i].first;
			int pWeight = saveParentNode[i].second;

			if(nodeMaxWeight[pNode] == pWeight)
				travelTree(i);
		}
	}

	cout << maxTreeDiameter << "\n";

	return 0;
}