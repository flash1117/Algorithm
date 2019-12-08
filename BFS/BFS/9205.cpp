#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n;
vector <pair<int, int>> vec;

typedef struct {
	int x, y, index;
}pos;

bool solve() {

	queue <pos> q;
	q.push({ vec[0].first, vec[0].second,0});

	while (!q.empty()) {

		int curX = q.front().x;
		int curY = q.front().y;
		int index = q.front().index+1;
		q.pop();

		if (curX == vec[vec.size()-1].first && curY == vec[vec.size() - 1].second)
			return true;

		cout << curX << " " << curY << endl;

		for (int i = index; i < vec.size(); i++)
		{

			int nextX = vec[i].first;
			int nextY = vec[i].second;
			
			if (abs((nextX + nextY) - (curX + curY)) > 1000) break;
			else {
				q.push({nextX, nextY, i});
				
			}
		}	
	}
	return false;
}

int main() {

	cin >> t;
	while (t--) {
		cin >> n;
		int input1, input2;
		for (int i = 0; i < n+2; i++)
		{
			cin >> input1 >> input2;
			vec.push_back(make_pair(input1, input2));
		}
		sort(vec.begin()+1, vec.end()-1, greater<>());

		bool ret = solve();
		if (ret) cout << "happy" << "\n";
		else cout << "sad" << "\n";
		vec.clear();
	}

	return 0;
}