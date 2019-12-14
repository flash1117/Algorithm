#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ret = 0;

void dfs(int depth, int sum, vector<int> numbers, int target) {

	if (depth == numbers.size() - 1) {
		if (sum == target) ret++;
		else return ;
	}

	dfs(depth + 1, sum + numbers[depth], numbers, target);
	dfs(depth + 1, sum - numbers[depth], numbers, target);

}

int solution(vector<int> numbers, int target) {
	
	dfs(0, 0, numbers, target);
	int answer = ret;
	return answer;
}

int main() {

	vector <int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(1);

	cout << solution(vec, 3);

	return 0;
}