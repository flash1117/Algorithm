#include <iostream>
#include <queue>

using namespace std;

int N;

int getAbsoluteNum(int input) {

	if (input < 0) return -input;
	return input;
}


struct cmp {
	bool operator()(int a, int b) {

		int absoluteA = getAbsoluteNum(a);
		int absoluteB = getAbsoluteNum(b);

		if (absoluteA == absoluteB) {
			return a > b;
		}
		else return absoluteA > absoluteB;


	}

};


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	priority_queue<int, vector<int> , cmp> pq;

	for (int i = 0; i < N; i++) {

		int input;
		cin >> input;

		if (input == 0) {

			if (pq.empty()) cout << 0 << "\n";
			else {
				cout <<pq.top()<< "\n";
				pq.pop();
			}

		}
		else {
			pq.push(input);
		}


	}



	return 0;
}
