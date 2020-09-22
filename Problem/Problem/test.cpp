#include <iostream>

using namespace std;

pair<int, int> map[20][20];

int main() {

	map[0][0].second = 1;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << map[i][j].second << " ";
		}
		cout << endl;
	}



	return 0;
}