#include <iostream>
#include <vector>

using namespace std;

#define Endl "\n"

int N;
// N �� �־�������, ���� ���� ������ ���ϱ�

int getCreateNum() {

	for (int i = 1; i < N; i++) {

		int buf = 0, q = 0;
		buf += i;

		q = i;
		while (1) {

			buf += q % 10;
			q /= 10;

			if (q < 1) break;

		}
		if (buf == N) return i;
	}

	return -1;
}


int main() {

	cin >> N;
	int ret = getCreateNum();

	if (ret == -1)
		cout << 0 << Endl;
	else
		cout << ret;

	return 0;
}