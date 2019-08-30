#include <iostream>

using namespace std;

int N, dst, cnt;
int coin[] = { 500, 100 ,50 ,10 ,5 ,1 };
void solve() {

	for (int i = 0; i < 6; i++) {

		if (dst >= coin[i])
		{
			cnt += dst / coin[i];
			dst = dst % coin[i];
		}
	}

}

int main() {

	cin >> N;
	dst = 1000 - N;

	solve();
	cout << cnt;
	return 0;
}