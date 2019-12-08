#include <iostream>
#include <string>
#include <vector>

using namespace std;

string key;

void solve() {

	char tmp;
	vector <char> vec;
	vector <char> temp;

	for (int i = 0; i < key.length(); i++) {

		if (key[i] == '<') {
			if (!vec.empty()) {
				tmp = vec.back();
				vec.pop_back();
				temp.push_back(tmp);
			}
		}
		else if (key[i] == '>') {
			if (!temp.empty()) {
				tmp = temp.back();
				temp.pop_back();
				vec.push_back(tmp);
			}
		}
		else if (key[i] == '-') {
			if (!vec.empty()) {
				vec.pop_back();
			}
		}
		else {
			vec.push_back(key[i]);
		}
	}

	while (!temp.empty()) {
		tmp = temp.back();
		temp.pop_back();
		vec.push_back(tmp);
	}

	for (int i = 0; i < vec.size(); i++) 
		cout << vec[i];
	cout << "\n";
	return;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		key = "";
		cin >> key;

		solve();
	}

	return 0;
}