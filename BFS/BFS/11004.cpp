#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector <int> vec;

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	
	sort(vec.begin(), vec.end());
	cout << vec[K - 1];
	
	return 0;
}