#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
bool visited[101];
vector <int> vec[101];
vector <int> white;
vector <int> blue;


void matchTeam(int index) {

	queue <pair<int, bool>> q;
	blue.push_back(index);
	visited[index] = true;
	for (int i = 0; i < vec[index].size(); i++) {
		q.push({ vec[index][i] , false});
		visited[vec[index][i]] = true;
	}

	while (!q.empty()) {

		int cur = q.front().first;
		bool isBlue = q.front().second;

		q.pop();

		if (isBlue) blue.push_back(cur);
		else white.push_back(cur);

		for (int i = 0; i < vec[cur].size(); i++) {

			bool next;
			if (isBlue) next = false;
			else next = true;

			if (!visited[vec[cur][i]]) {
				q.push({ vec[cur][i], next});
				visited[vec[cur][i]] = true;
			}

		}
		
	}

	return;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, pNum;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> pNum;
			vec[i + 1].push_back(pNum);
			vec[pNum].push_back(i + 1);
		}
	}

	
	for (int i = 1; i <= n; i++) {

		if (!visited[i]) {
			matchTeam(i);
		}
	}

	cout << blue.size() << "\n";
	for (int i = 0; i < blue.size(); i++) cout << blue[i] << " ";
	cout << "\n";
	cout << white.size() << "\n";
	for (int i = 0; i < white.size(); i++) cout << white[i] << " ";
	cout << "\n";

	return 0;
}