#include <iostream>

using namespace std;

void test1(int& a) {

	cout <<  &a << a << endl;
	a++;
}

void test2(int* a) {

	cout << a  << *a << endl;
}

int main() {

	int a = 1;

	test1(a);
	test2(&a);


	return 0;
}