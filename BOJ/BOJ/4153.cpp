#include <iostream>

using namespace std;


bool isRightAngle(int x , int y, int  z) {

	if (z > y && z > x && z * z == x * x + y * y) return true;
	else if (y > z && y > x && y * y == x * x + z * z) return true;
	else if (x > z && x > y && x * x == y * y + z * z) return true;

	return false;
}

int main() {

	int x, y, z;
	
	while (1) {
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) break;

		if (isRightAngle(x, y, z)) cout << "right\n";
		else cout << "wrong\n";

	}


	return 0;
}