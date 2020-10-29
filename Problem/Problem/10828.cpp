#include <iostream>
#include <stack>

using namespace std;

int N;

int main() {

	cin >> N;
	stack<int> st;

	while (N--) {

		string _order;
		cin >> _order;

		if (_order == "push") {
			int pushValue;
			cin >> pushValue;

			st.push(pushValue);

		}
		else if (_order == "top") {
			if (st.empty()) cout << -1 << "\n";
			else cout << st.top() << "\n";

		}
		else if (_order == "size") {

			cout << st.size() << "\n";
		}
		else if (_order == "empty") {

			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (_order == "pop") {

			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}


		}


	}
	

	return 0;
}