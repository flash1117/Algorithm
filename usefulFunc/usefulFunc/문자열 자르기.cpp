#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

template<typename Out>
void split(const string& s, char delim, Out result) {

	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
		* (result++) = item;
}

vector<string> split(const string& s, const char delim) {

	vector <string> elems;
	split(s, delim, back_inserter(elems));

	return elems;
}

void print( vector<string>& vec) {

	for (int i = 0; i < vec.size(); i++) {

		string temp = vec[i];
		cout << temp << endl;

	}

}

int main() {

	vector <string> x = split("one,two,,three", ',');
	// 중간에 공백이 들어감
	print(x);
	return 0;

}