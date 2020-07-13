#include <iostream>
#include <vector>

using namespace std;


int n, l;
typedef struct
{
	int D, R, G;
}Pos;
vector <Pos> vec;

void solve() {

	int index = 0;
	int cnt = 0;
	while (index != l) {



	}

}

int main() {

	Pos input;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> input.D >> input.R >> input.G;
		vec.push_back(input);
	}

	solve();

	return 0;
}