#include <iostream>

using namespace std;

int main() {

	int N, r,e,c;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> r >> e >> c;
		if (r > e - c) {
			cout << "do not advertise\n";
		}
		else if (r == e - c) {
			cout << "does not matter\n";
		}
		else
			cout << "advertise\n";


	}

	return 0;
}