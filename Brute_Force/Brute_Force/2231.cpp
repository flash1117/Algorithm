#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int > digit;

void solve(){
	int q = N;
	for (int i = 0; i < 6; i++) {

		digit.push_back(q % 10);
		if (q < 10) break;
		q = q / 10;
		
	}

}

int main() {

	cin >> N;

	solve();
	return 0;
}