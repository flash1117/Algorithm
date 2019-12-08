#include <iostream>
#include <vector>

using namespace std;

int N1, N2, T;
vector<char> vec1;
vector<char> vec2;

void solve() {

	vector <char> vec;

	for (int i = vec1.size() - 1; i >= T; i--) {
		vec.push_back(vec1[i]);
	}

	int index = T-1;
	for (int i = 0; i < 2 * T; i++) {

		if (i % 2 == 0) {
			if(i/2 < vec2.size() && i/2 >=0)
				vec.push_back(vec2[i/2]);
		}
		else {
			if (index >= 0 && index < vec1.size()) {
				vec.push_back(vec1[index]);
			}
			index--;
		}
	}

	for (int i = T; i < vec2.size(); i++)
		vec.push_back(vec2[i]);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
}

int main() {

	char temp;
	cin >> N1 >> N2;
	for (int i = 0; i < N1; i++)
	{
		cin >> temp;
		vec1.push_back(temp);
	}

	for (int i = 0; i < N2; i++) {
		cin >> temp;
		vec2.push_back(temp);
	}
	cin >> T;
	solve();

	return 0;
}