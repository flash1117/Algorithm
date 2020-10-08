#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 1003002;
int N;
bool primeNum[MAX_SIZE];

bool isPalindrome(int num) {

	vector<int> digitNum;
	int _num = num;
	int reverseNum = 0;
	while (_num) {

		digitNum.push_back(_num % 10);
		_num /= 10;

	}

	for (int i = 0; i < digitNum.size(); i++) {

		reverseNum *= 10;
		reverseNum += digitNum[i];
	}

	if (reverseNum == num) return true;

	return false;
}


int getPalinedromePrimeNumber()
{

	for (int i = 2; i < MAX_SIZE; i++) {
		bool isPelinNum = false;

		if (!primeNum[i]) {

		//	cout << i << " ";

			if(i>=N) isPelinNum = isPalindrome(i);
			if (isPelinNum) return i;
			else {

				for (int j = 2; i * j < MAX_SIZE; j++) {
					primeNum[i * j] = true;
				}

			}


		}

	}

	return -1; // error

}


int main() {

	cin >> N;

	cout << getPalinedromePrimeNumber() << "\n";

	return 0;
}