#include <iostream>
#include <cstring>
using namespace std;

int k;
int s[13], ret[13];
bool visited[13];

void DFS(int depth, int cnt) {

	if (depth == 6) {

		for (int i = 0; i < 6; i++)
				cout << ret[i] << " ";
		cout << endl;
		return;
	}
	
	for (int i = cnt; i < k; i++) {

		ret[depth] = s[i];
		DFS(depth + 1, cnt + 1);
	//	ret[depth] = -1;
	}
}


int main() {

	while (1) {

		cin >> k;
		if (k == 0) break;
		else {

			for (int i = 0; i < k; i++) 
				cin >> s[i];
			
		}


		DFS(0,0);
		cout << endl;
		memset(visited, false, sizeof(visited));
		memset(s, 0, sizeof(s));

	}

}