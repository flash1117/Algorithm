#include <iostream>
using namespace std;

const double pi = 3.14159265358979323846;

int main() {
	double R = 0.0;
	cin >> R;
	cout << fixed;
	cout.precision(6);

	cout << R * R * pi << endl;
	cout << R * R * 2 << endl;
	return 0;
}