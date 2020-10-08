#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input1, input2;

	getline(cin, input1);
	getline(cin, input2);

	int i = 0;
	int ret = 0;
	while (i < input1.length()) {

		if (input2.length() > input1.length() - i) break;

		if (input1[i] == input2[0]) {
			bool state = true;
			for (int j = 0; j < input2.length(); j++) {

				if (input1[i + j] != input2[j]) {
					state = false;
					break;
				}
			}
			if (state) {
				ret++;
				i += input2.length();
			}
			else i++;
		}
		else i++;

	}


	cout << ret << "\n";
	return 0;
}