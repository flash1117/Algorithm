#include <iostream>

using namespace std;


typedef struct {

	int plus, minus, mul, div;

}Operation;


int numCnt;
int arr[11];
Operation op;

int main() {

	cin >> numCnt;
	for (int i = 0; i < numCnt; i++) {

		cin >> arr[i];
	}

	cin >> op.plus >> op.minus >> op.mul >> op.div;




	return 0;
}