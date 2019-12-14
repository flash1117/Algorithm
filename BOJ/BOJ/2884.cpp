#include <iostream>

using namespace std;

int h, m;

int main() {

	cin >> h >> m;
	if (m < 45) {
		m = 60 - (45 - m);
		if (h != 0) h--;
		else h = 23;
	}
	else m -= 45;
	cout << h << " " << m;
	return 0;
}