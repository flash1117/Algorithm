#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> m;
const int PRIME_NUMBER_SIZE = 100000 + 1;
bool primeNumber[PRIME_NUMBER_SIZE]; // false is prime number

void primeNumberInit() {

	primeNumber[0] = true; primeNumber[1] = true;

	for (int i = 2; i <= PRIME_NUMBER_SIZE; i++) {

		if (!primeNumber[i]) {

			for (int j = 2; i * j <= PRIME_NUMBER_SIZE; j++) {
				primeNumber[i * j] = true;
			}
		}
	}

}


string getMapKey(int numerator, int denominator) { // 분자 분모

	return to_string(numerator) + to_string(denominator);

}

int getMaxAnswer() {
	int maxAnswer = 0;

	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		maxAnswer = max(maxAnswer, iter->second);
	}

	return maxAnswer;
}

int solution(vector<int>& X, vector<int>& Y) {

	primeNumberInit();

	string index = "";
	int answer = 0;

	for (int i = 0; i < X.size(); i++) {

		if (X[i] == 0) {
			index = to_string(0);
			m[index]++;
		}
		else {

			bool divideState = true;
			while (divideState) {

				divideState = false;
				for (int j = 2; j < PRIME_NUMBER_SIZE; j++) {
					if (!primeNumber[j] && X[i] % j == 0 && Y[i] % j == 0) {
						divideState = true;
						X[i] /= j;
						Y[i] /= j;
						break;
					}
				}

			}

			index = getMapKey(X[i], Y[i]);
			m[index]++;
		}
	}

	answer = getMaxAnswer();

	return answer;
}

int main() {


	cout << 4 % 0 << endl;
	return 0;
}