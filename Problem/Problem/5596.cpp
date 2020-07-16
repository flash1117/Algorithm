#include <iostream>

using namespace std;

typedef struct {
	int a, b, c, d;
}Test;

int main() {

	int sum1 = 0, sum2 = 0;
	Test input1, input2;

	cin >> input1.a >> input1.b >> input1.c >> input1.d;
	cin >> input2.a >> input2.b >> input2.c >> input2.d;

	sum1 = input1.a + input1.b + input1.c + input1.d;
	sum2 = input2.a + input2.b + input2.c + input2.d;

	int ret = sum1 >= sum2 ? sum1 : sum2;
	cout << ret << endl;

	return 0;
}