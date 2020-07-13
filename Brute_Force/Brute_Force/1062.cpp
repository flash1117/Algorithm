#include <iostream>
#include <vector>

using namespace std;

int n, k, maxRead;
int pick[27];
vector <string> _word;

void teachLanguage(int depth, int cnt) {

	if (depth > 26) return;

	if (cnt == k) {
		bool visited[27];
		for (int i = 0; i < 27; i++) visited[i] = false;
		for (int i = 0; i < k; i++) visited[pick[i]] = true;
			
		int cnt = 0;

		for (int i = 0; i < _word.size(); i++) {
			bool state = true;
			for (int j = 0; j < _word[i].length(); j++) {
				if (!visited[_word[i][j] - 'a']) {
					state = false;
					break;
				}
			}
			if (state) cnt++;
		}
		
		maxRead = maxRead > cnt ? maxRead : cnt;

		return;
	}

	if (depth == 0 || depth == 2 || depth == 8 || depth == 13 || depth == 19) teachLanguage(depth + 1, cnt);
	else {
		pick[cnt] = depth;
		teachLanguage(depth + 1, cnt + 1);
		teachLanguage(depth + 1, cnt);
	}


	return;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input;
		_word.push_back(input);
	}


	pick[0] = 0;
	pick[1] = 2;
	pick[2] = 8;
	pick[3] = 13;
	pick[4] = 19;
	if (k < 5) {
		cout << 0 << "\n";
		return 0;
	}
	else teachLanguage(0, 5);
	cout << maxRead << "\n";
	return 0;
}