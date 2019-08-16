#include <iostream>
#include <vector>

using namespace std;

#define Endl "\n"
int N;
vector <pair<int, int>> consulting;
int benefit[16];
int maxBenefit;

void solve() {

	for (int i = 0; i < consulting.size(); i++) {



		if (benefit[consulting[i].first] < consulting[i].second)
			benefit[consulting[i].first] = consulting[i].second;


	}

}

int main() {

	cin >> N;
	int T, P;
	for (int i = 0; i < N; i++) {

		cin >> T >> P;
		consulting.push_back(make_pair(T, P));

	}

	solve(0, 0);
	return 0;
}