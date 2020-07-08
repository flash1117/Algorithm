#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> vec[50];

int getFriend(int index) {

	queue<pair<int,int>> q;
	int ret = 0;
	bool visited[50];
	
	for (int i = 0; i < n; i++)	visited[i] = false;

	visited[index] = true;

	for (int i = 0; i < vec[index].size(); i++) {
		q.push({ vec[index][i] ,1 });
		visited[vec[index][i]] = true;
	}

	while (!q.empty()) {

		int cur = q.front().first;
		int ccnt = q.front().second;
		q.pop();


		if (ccnt > 2) continue;
		ret++;

		for (int i = 0; i < vec[cur].size(); i++) {

			if (!visited[vec[cur][i]]) {

				q.push({ vec[cur][i], ccnt + 1 });
				visited[vec[cur][i]] = true;

			}
		}

	}


	return ret;
}


int main()
{
	int ret = 0;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = i; j < n; j++) {
			if (input[j] == 'Y') {
				vec[i].push_back(j);
				vec[j].push_back(i);
			}
			
		}
	}


	for (int i = 0; i < n; i++) {
		int _friend = getFriend(i);

		ret = ret > _friend ? ret : _friend;
	}
	cout << ret << "\n";
	
	return 0;
}