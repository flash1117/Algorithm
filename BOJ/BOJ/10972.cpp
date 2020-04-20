#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, input;
	vector <int> Ary;
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> input;
		Ary.push_back(input);

	}
	bool state = false;
	while (next_permutation(Ary.begin(), Ary.end())) {
		state = true;
		for (int i = 0; i < n; i++) {
			cout << Ary[i] << " ";
		}
		cout << "\n";
		break;
	}
	if (!state) cout << -1 << "\n";
	return 0;
}