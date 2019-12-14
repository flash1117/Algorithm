#include <iostream>
#include <vector>
using namespace std;

int a, b, c;
vector <int> ret = {0,0,0,0,0,0,0,0,0,0};

void setVec(int mul) {

	while (mul > 10) {

		ret[mul % 10]++;
		mul /= 10;

	}
	ret[mul]++;
}


int main() {

	cin >> a >> b >> c;
	int mul = a * b * c;
	setVec(mul);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << "\n";
	}
	return 0;
}