#include <iostream>
#include <queue>
using namespace std;

int N;

void printException() {

	cout << -1 << "\n";
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++) {

		string input;
		cin >> input;

		if (input == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (input == "front") {
			if (q.empty()) printException();
			else cout << q.front() << "\n";
		}
		else if (input == "back") {
			if (q.empty()) printException();
			else cout << q.back() << "\n";
		}
		else if (input == "size") {
			cout << q.size() << "\n";
		}
		else if (input == "pop") {
			if (q.empty()) printException();
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (input == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}

	return 0;
}