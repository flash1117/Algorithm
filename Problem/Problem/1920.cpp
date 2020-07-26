#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int src[100001];

void printIsExist(int goal, int start, int end) {

	int mid = (start + end) / 2;

	if (src[mid] == goal) {
		cout << 1 << "\n";
		return;
	} 
	else if (start >= end) {
		cout << 0 << "\n";
		return;
	}

	if (src[mid] < goal) {
		printIsExist(goal, mid+1, end);
		return;
	}
	else {
		printIsExist(goal, start, mid-1);
		return;
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m,input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> src[i];
	}

	sort(src, src+n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		
		cin >> input;
		printIsExist(input, 0, n-1);

	}
	return 0;
}