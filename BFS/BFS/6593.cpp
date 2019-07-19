#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

char map[31][31][31];
bool visited[31][31][31];
int L, R, C;

void print() {

	for (int i = 0; i < L; i++) {
		
		for (int j = 0; j < R; i++) {
			
			for (int k = 0; k < C; k++) {
				cout << map[j][k][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void BFS() {


}

int main() {

	string temp = "", temp2 = "";

	while (1) {
		cin >> L >> R >> C;
		memset(visited, false, sizeof(visited));
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; i++) {
				cin >> temp;
				for (int k = 0; k < C; k++) {
					map[j][k][i] = temp[k];
				}
			}
			cin >> temp2;
		}

	//	print();

	}
	
	return 0;
}