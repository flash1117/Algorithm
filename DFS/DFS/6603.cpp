#include <iostream>
#include <cstring>
using namespace std;

int k;
int s[13], ret[13];
bool visited[13];

void DFS(int depth, int cnt) {

	if (cnt == 6) {

		for (int i = 0; i < 6; i++)
			cout << ret[i] << " ";
		cout << endl;
		return;
	}


	for (int i = depth; i < k; i++) {
		ret[cnt] = s[i];
		DFS(i+1, cnt + 1);
	}

}


int main() {

	while (cin >> k && k) {

		for (int i = 0; i < k; i++) 
			cin >> s[i];

		DFS(0,0);
		cout << endl;
		memset(s, 0, sizeof(s));

	}

}