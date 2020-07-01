#include <iostream>
#include <vector>

using namespace std;

int n, m;

typedef struct {
	int order, firstSet, secondSet;
}Input;

vector <Input> TC;

void solve() {



}

int main() {

	Input input = {0,0,0};

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		
		cin >> input.order >> input.firstSet >> input.secondSet;
		TC.push_back(input);
	}

	return 0;
}