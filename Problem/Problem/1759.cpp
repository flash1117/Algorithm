#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[16];
char pick[16];
bool isCollection(char ch) {

	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
	return false;

}

void makePassword(int depth, int cnt, int collectionCnt, int consonantCnt)
{
	if (cnt == L && collectionCnt > 0 && consonantCnt > 1) {

		for (int i = 0; i < L; i++)
			cout << pick[i];
		cout << "\n";

		return;
	}
	else if (cnt == L) return;

	if (depth >= C) return;
	
		if (isCollection(arr[depth]))
		{
			pick[cnt] = arr[depth];
			makePassword(depth + 1, cnt + 1, collectionCnt + 1, consonantCnt);
			makePassword(depth + 1, cnt, collectionCnt, consonantCnt);
		}
		else {
			pick[cnt] = arr[depth];
			makePassword(depth + 1, cnt + 1, collectionCnt, consonantCnt + 1);
			makePassword(depth + 1, cnt, collectionCnt, consonantCnt);

		}

	return;
}
int main() {

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + C);

	makePassword(0, 0, 0, 0);
	return 0;
}