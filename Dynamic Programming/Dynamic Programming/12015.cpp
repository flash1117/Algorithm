#include <iostream>
#include <vector>

using namespace std;

int N;
int input[1000002];
vector <int> Lis;

void print() {

	for (int i = 0; i < Lis.size(); i++) {

		cout << Lis[i] << " ";
	}
	cout << endl;
}

void solve() {


	for (int i = 1; i <= N; i++) {



	}
	print();
	cout << Lis.size() - 1;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> input[i];

	solve();

	return 0;
}