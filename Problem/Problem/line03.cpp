#include <string>
#include <vector>

using namespace std;

int answer;
vector<int> breakPoint;

void dfs(string road, int n, int cnt) {

	if (cnt == n) {
		int con = 0, answer = 0;
		for (int i = 0; i < road.length(); i++) {

			if (road[i] == '1') {

				con++;
				answer = con > answer ? con : answer;
			}
			else
				con = 0;
			
		}

		return;
	}


	dfs

}

int solution(string road, int n) {
	
	for (int i = 0; i < road.length(); i++) {
		if (road[i] == '0') breakPoint.push_back(i);
	}


	return answer;
}

int main() {

	dfs("111011110011111011111100011111", 3, 0);


	return 0;
}