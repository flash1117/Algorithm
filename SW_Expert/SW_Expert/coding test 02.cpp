#include <iostream>

using namespace std;

char input;
int num[10], ret[10];
int k, Len;

void DFS(int depth, int cnt) {

	if (cnt == Len)
	{
		for (int i = 0; i < Len; i++)
			cout << ret[i] << " ";
		cout << endl;
		return;
	}

	for (int i = depth; i < Len; i++) {
		ret[cnt] = num[i];
		DFS(i + 1, cnt + 1);
	}
}

int main(void) {

	while (cin >> input) {

		if (input == '\n') break;
		if (input == ' ');
		else {
			num[Len] = input - '0';
			Len++;
		}
	}
	cin >> k;

	DFS(0, 0);

	return 0;
}