#include <iostream>

using namespace std;

bool visited[27];

int main() {

	int n, cnt=0;
	string input;
	cin >> n;

	for (int i = 0; i < n; i++) {

		bool isGroupWord = true;
		for (int j = 0; j <= 'z' - 'a'; j++) {
			visited[j] = 0;
		}

		cin >> input;
		for (int j = 0; j < input.length(); j++) {

			if (visited[input[j] - 'a'] && input[j-1] != input[j]) {
				isGroupWord = false;
				break;
			}
			else visited[input[j] - 'a'] = true;

		}
		if (isGroupWord) cnt++;
	}


	cout << cnt << "\n";
	return 0;
}