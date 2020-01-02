#include <iostream>

using namespace std;

int main() {

	int a, b, upBound = 0, xCharge=0, water;
	cin >> a >> b;
	cin >> upBound;
	cin >> xCharge;
	cin >> water;

	int ret1 = 0, ret2 = b;
	ret1 = a * water;
	if (water > upBound) ret2 += (water - upBound) * xCharge;

	if (ret1 > ret2) cout << ret2 << "\n";
	else cout << ret1 << "\n";

	return 0;
}