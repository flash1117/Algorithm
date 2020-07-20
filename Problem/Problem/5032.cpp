#include <iostream>

using namespace std;


int main() {

	int e, f, c, bottle =0, canDrink =0;
	cin >> e >> f >> c;
	canDrink = (e + f) / c;

	int ret = canDrink;

	bottle = (e + f) % c;

	while (canDrink >= 1) {

		bottle += canDrink;
		canDrink = bottle / c;
		bottle %= c;
		ret += canDrink;
	}

	cout << ret << "\n";
	return 0;
}