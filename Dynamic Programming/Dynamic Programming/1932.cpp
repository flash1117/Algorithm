#include <iostream>
#include <vector>

using namespace std;

#define Endl "\n"

int n;
vector <int> vec[501];

void print() {

	cout << Endl;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i].empty()) return;
			cout << vec[i][j] << " ";

		}
		cout << Endl;
	}

}

void solve() {




}


int main() {

	int input;
	cin >> n;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < i; j++) {

			cin >> input;
			vec[i].push_back(input);
		}

	}

	print();
	solve();
	return 0;
}