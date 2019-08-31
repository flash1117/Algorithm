#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string N;

int solve() {

	int ret = 0, pos =1;
	vector <int> vec;

	for (int i = 0; i < N.length(); i++) 
		vec.push_back(N[i] - '0');

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		ret += vec[i] * pos;
		pos *= 10;
	}
	if (ret % 30 == 0) return ret;
	
	return -1;

}

int main() {

	cin >> N;
	cout << solve();

	return 0;
}