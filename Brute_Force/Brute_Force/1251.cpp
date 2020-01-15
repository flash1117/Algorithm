#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<char> vec;
int pick[4];
vector <string> ret;

void dfs(int depth, int cnt) {

	if (depth > vec.size()) return;
	else if (cnt == 3) {

		string temp = "";
		for (int i = pick[1] - 1; i >= 0; i--) 
			temp.push_back(vec[i]);
		for (int i = pick[2] - 1; i >= pick[1]; i--)
			temp.push_back(vec[i]);
		for (int i = vec.size() - 1; i >= pick[2]; i--)
			temp.push_back(vec[i]);
		
		ret.push_back(temp);
		return;
	}

	pick[cnt] = depth;
	dfs(depth + 1, cnt + 1);
	pick[cnt] = 0;

	dfs(depth + 1, cnt);

}

int main() {

	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
		vec.push_back(input[i]);

	dfs(0, 0);
	sort(ret.begin(), ret.end());
	cout << ret[0] << "\n";

	return 0;
}