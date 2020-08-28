#include <iostream>

using namespace std;

int pick[10];

void getComb(int depth, int cnt) {

	if (depth > 3) return;
	else {
		for (int i = 0; i < cnt; i++) {
			cout << pick[i] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		pick[cnt] = i;
		getComb(depth + 1, cnt + 1);
		getComb(depth + 1, cnt);
	}
	
	return;
}

int main() {

	getComb(0, 0);


	return 0;
}