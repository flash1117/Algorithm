#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[10001];

vector<string> solution(vector<vector<string>> forms) {
	vector<string> answer;

	for (int i = 0; i < forms.size(); i++) {

		for (int j = i + 1; j < forms.size(); j++) {

			for (int k = 0; k < forms[i][1].length() - 1; k++) {
				if (forms[i][1][k] == forms[j][1][k]) {

					if (k + 1 >= forms[j][1].length()) break;
					if (forms[i][1][k + 1] == forms[j][1][k + 1]) {
						if (!visited[i]) {
							visited[i] = true;
							answer.push_back(forms[i][0]);
						}
						if (!visited[j]) {
							visited[j] = true;
							answer.push_back(forms[j][0]);
						}
						break;
					}
				}
			}
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}