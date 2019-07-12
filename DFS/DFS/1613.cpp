#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k, s, ret =0;
vector <int> vec[401];
vector <int> rvec[401];
bool visited[401], r;

void DFS(int h1, int dst) {

	if (visited[h1]) return ;
	visited[h1] = true;

	if (h1 == dst)
	{
		
		ret = -1;
		return ;
	}
	if (r == false) {

		for (int i = 0; i < vec[h1].size(); i++) {

			DFS(vec[h1][i], dst);
		}
	}
	else if(r == true){ // 이 안으로 안들어온다 왜죠
		for (int i = 0; i < rvec[h1].size(); i++) {
			
			DFS(rvec[h1][i], dst);
		}
	}
	
}

int main() {

	int h1, h2;
	
	cin >> n >> k;

	for (int i = 0; i < k; i++) {

		cin >> h1 >> h2;
		vec[h1].push_back(h2);
		rvec[h2].push_back(h1);
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		ret = 0;
		r = false;
		memset(visited, false, sizeof(visited));
		cin >> h1 >> h2;
		DFS(h1, h2);
		if (ret != -1) {
			r = true;
			memset(visited, false, sizeof(visited));
			DFS(h2, h1);
			if (ret == -1) ret = ret * (-1);
		}
		cout << ret << endl;
	}

}