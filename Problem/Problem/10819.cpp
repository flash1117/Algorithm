#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> vec;

void print() {

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int getMax() {
	int sum = 0;
	do {
	//	print();
		int _sum = 0;
		for (int i = 0; i < vec.size()-1; i++) {
			_sum += abs(vec[i] - vec[i + 1]);

	//		cout << abs(vec[i] - vec[i + 1]) << " ";

		}
		
	//	cout << "\n" << "total : " << _sum << endl;

		sum = _sum > sum ? _sum : sum;
	} while (next_permutation(vec.begin(), vec.end()));

	return sum;
}


int main() {

	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);

	}
	
	sort(vec.begin(), vec.end());
	cout << getMax() << "\n";


	return 0;
}