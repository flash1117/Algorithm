#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int index = 0;
	string input;
	map<string, double> _map;

	while (getline(cin, input)) {

		index++;
		_map[input]++;
	}
	cout << fixed;
	cout.precision(4);

	for (auto iter = _map.begin(); iter != _map.end(); iter++) {

		string _name = iter->first;
		double _percent = iter->second;

		_percent /= index;
		_percent *= 100.0;
		cout << _name << " " << _percent << "\n";
	}

	return 0;
}