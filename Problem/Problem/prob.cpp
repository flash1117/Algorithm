#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> vec = { 1,2,3,4,5 };

void print() {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

bool isBoundary(int x, int y) {

	if (i < 0 || i>4) return false;
	return true;

}
int main() {

	int cnt = 0;
	do {
		bool state = true;
		for (int i = 0; i < vec.size(); i++) {
			
			if (vec[0] == 1 && vec[4] == 3 && vec[1] != 2) {
				state = false;
				break;
			}
			else if (i > 0 && vec[i] == 1 && vec[i - 1] == 3 && (i<=3 && vec[i+1]!=2)) {
				state = false;
				break;
			}
			else if (i + 1 <= 4 && vec[i] == 1 && vec[i + 1] == 3) {
				state = false;
				break;
			}
			
		}
		
		if (!state) continue;
		else { print(); cnt++; }

	} while (next_permutation(vec.begin(), vec.end()));
	
	cout << cnt << endl;
	return 0;
}