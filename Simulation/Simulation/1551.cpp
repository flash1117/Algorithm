#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

int N, K;
int res[21];

template<typename Out>
void split(const string& s, char delim, Out result) {

	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		* (result++) = item;
}

vector<int> split(const string& s, const char delim) {

	vector <string> elems;
	split(s, delim, back_inserter(elems));

	vector <int> ret;

	for (int i = 0; i < elems.size(); i++)
		ret.push_back(stoi(elems[i]));
	
	return ret;
}

void solve(vector<int>& vec) {

	int arraySize = vec.size();

	for (int i = 0; i < K; i++) {

		for (int j = 0; j < arraySize - 1; j++) {

			vec[j] = vec[j + 1] - vec[j];
		}

		arraySize--;
	}

	for (int j = 0; j < arraySize; j++) {

		cout << vec[j];
		if (j != arraySize - 1) cout << ",";
		else cout << "\n";

	}
}

int main() {

	string input;
	cin >> N >> K;
	cin >> input;

	vector <int> vec = split(input, ',');

	solve(vec);

	return 0;

}