#include <iostream>

using namespace std;

int x, y;
string week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
void solve() {

	int day = 0;
	for (int i = 1; i < x; i++) {

		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			day += 31;
		}
		else if(i==2) {
			day += 28;
		}
		else {
			day += 30;
		}
	}
	day += y;
	day %= 7;

	cout << week[day];
	
}

int main() {

	cin >> x >> y;
	solve();

	return 0;
}