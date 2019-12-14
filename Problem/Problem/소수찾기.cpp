#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int answer = 0;
bool pNum[10000001], visited[10000001];
vector <int> vec, pick;

void initValue(int len, string &input) {
	
	int bound = 1;

	for (int i = 0; i < len; i++)
		bound *= 10;
	
	pNum[0] = true; pNum[1] = true;
	for (int i = 2; i <= bound; i++) { // prime number set

		if (!pNum[i]) {
			for (int j = 2; j <= bound / i; j++) {
				pNum[i * j] = true;
			}
		}	
	}

	for (int i = 0; i < input.length(); i++) // string to int
		vec.push_back(input[i]-'0');
	
}

void dfs(int depth, int cnt, int goal) {

	if (cnt == goal) {
		
		vector <int> temp = pick;
		do {
			int digit = 1, sum =0;
			for (int i = temp.size() - 1; i >= 0; i--) {
				sum += temp[i] * digit;
				digit *= 10;
			}

			if (!pNum[sum] && !visited[sum]) {
			
				answer++;
				visited[sum] = true;
			}

		} while (next_permutation(temp.begin(), temp.end()));
		
		temp.clear();
		return;
	}
	else {
		int _digit = 1, _sum = 0;
		for (int i = pick.size() - 1; i >= 0; i--) {
			_sum += pick[i] * _digit;
			_digit *= 10;
		}
		visited[_sum] = true;

	}
	for (int i = depth; i < vec.size(); i++) {
		pick.push_back(vec[depth]);
		
		int _digit = 1, _sum = 0;
		for (int i = pick.size() - 1; i >= 0; i--) {
			_sum += pick[i] * _digit;
			_digit *= 10;
		}
		if (!visited[_sum]) 
			dfs(depth + 1, cnt + 1, goal);
		
		pick.pop_back();
	}

}

int main() {

	string numbers = "17";
	
	initValue(numbers.length(), numbers);
	
	for(int i=0;i<vec.size(); i++)
		if (!visited[vec[i]] && !pNum[vec[i]]) {
			visited[vec[i]] = true;
			answer++;
		}

	for (int i = 2; i <= vec.size(); i++) {
		dfs(0,0,i);
		pick.clear();
	}
	
	return 0;
}