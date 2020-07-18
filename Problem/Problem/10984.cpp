#include <iostream>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		double temp = 0;
		int term=0, sum = 0, input=0;
		double score = 0.0, scoreSum = 0.0;
		cin >> term;
		for (int i = 0; i < term; i++) {
			cin >> input >> score;
			sum += input;
			scoreSum += score;

			temp += input * score;
		}
		cout.precision(2);
		if(temp !=0)
		cout << sum << " "<<temp / sum << endl;
		else cout << sum << " " << 0.0 << endl;
	}

	return 0;
}