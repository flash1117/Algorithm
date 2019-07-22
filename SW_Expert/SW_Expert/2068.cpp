#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int T, cnt =1, ret=0;
	vector <int> vec;

	cin >> T;
	while (T--) {
	
		for (int i = 0; i < 10; i++) {
			cin >> ret;
			vec.push_back(ret);
		}

		sort(vec.begin(), vec.end());

		cout << "#" << cnt++ <<  " " << vec[9] << endl;
		vec.clear();
	}


	return 0;
}