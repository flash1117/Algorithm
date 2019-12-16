#include <iostream>
#include <vector>

using namespace std;

int alphaCnt[30];
vector <char> ret;

int main() {

	int N;
	string input;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> input;
		alphaCnt[input[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alphaCnt[i] >= 5) ret.push_back(i + 'a');
	}


	if (ret.empty()) {
		cout << "PREDAJA\n";
	}
	else
	{
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i];
	}
	return 0;
}