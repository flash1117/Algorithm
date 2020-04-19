#include <iostream>
#include <vector>

using namespace std;

bool primeNum[10001];
vector <int> vec;
void findPrimeNum() {

	for (int i = 2; i < 10001; i++) {

		primeNum[0] = true;
		primeNum[1] = true;

		if (!primeNum[i]) {
			
			for (int j = i + 1; j < 10001; j++) 
				if (j % i == 0) primeNum[j] = true;

		}

	}
}

int main() {

	int input1, input2;
	cin >> input1 >> input2;
	int minNum = input1 > input2 ? input2 : input1;
	findPrimeNum();
	int gcd = 1;
	while (1) {
		int t = 2;
		for (int i = 2; i <= minNum; i++) {
			
			if (!primeNum[i] && input1 % i == 0 && input2 % i == 0) {
				gcd *= i;
				input1 /= i;
				input2 /= i;
				break;
			}
			t++;
		}
		if (t > minNum) break;
	}
	cout << gcd << "\n" << gcd * input1 * input2 <<"\n";
	return 0;
}