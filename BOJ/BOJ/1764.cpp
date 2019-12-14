#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> input;
vector <string> ret;


int main() {

	ios::sync_with_stdio(false);
	string temp;
	int N, M, answer=0;
	cin >> N >> M;
	for (int i = 0; i < N+M; i++) {
		cin >> temp;
		input.push_back(temp);
	}
	
	sort(input.begin(), input.end());

	for (int i = 0; i < input.size()-1; i++) {
		if (input[i] == input[i + 1]) {
			answer++;
			ret.push_back(input[i]);
			i++;
		}
	}
	cout << answer << "\n";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << "\n";
	}
	

	return 0;
}