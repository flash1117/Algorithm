#include <iostream>
#include <stack>
using namespace std;

bool isValidPS(string VPS) {

	stack <char> st;

	for (int i = 0; i < VPS.length(); i++) {

		if (VPS[i] == '(') {
			st.push('(');
		}
		else if (VPS[i] == ')') {
			if (st.empty()) return false;
			else st.pop();
		}
	}

	if (st.empty()) return true;
	else return false;
}

int main() {

	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {

		string VPS;
		cin >> VPS;

		if (isValidPS(VPS)) {
			cout << "YES\n";
		}
		else cout << "NO\n";


	}







	return 0;
}