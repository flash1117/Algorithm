#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int T;
bool visited[10000];
vector <pair<string, string>> vec;

bool isPrime(int x) {

	for (int i = 2; i < x; i++) 
		if (x % i == 0)
			return false;

	return true;
}

int strToint(string input) {
	int output = 0;
	int temp;
	for (int i = 0; i < input.length(); i++) {

		temp = input[i] - '0';
		for (int j = 0; j < input.length() - i-1; j++)
			temp *= 10;
		
		output += temp;
	}
	return output;
}


int BFS(int testCase) {

	queue <pair<string, int>> q;
	q.push({ vec[testCase].first, 0 });
	visited[strToint(vec[testCase].first)] = true;

	while (!q.empty()) {

		string cur = q.front().first;
		int ccnt = q.front().second;


	}

}


int main() {

	string temp1, temp2;
	cin >> T;

	while (T--) {
		cin >> temp1 >> temp2;
		vec.push_back(make_pair(temp1, temp2));
	}

	for (int i = 0; i < vec.size(); i++) 
		BFS(i);
	

	return 0;
}