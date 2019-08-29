#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ret;
vector <int> vec;
int greedy[1001];

void solve() {

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {

		if (i == 0) greedy[0] = vec[0];
		else greedy[i] = vec[i] + greedy[i - 1];
		
	}

	for (int i = 0; i < vec.size(); i++)
		ret += greedy[i];

}

int main() {

	int input;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		vec.push_back(input);

	}

	solve();
	cout << ret;

	return 0;
}