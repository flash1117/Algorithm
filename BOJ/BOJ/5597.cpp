#include <iostream>

using namespace std;

bool visited[31];
int main() {

	int temp;
	for (int i = 0; i < 28; i++) {
		cin >> temp;
		visited[temp] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!visited[i]) cout << i << "\n";
	}
	
	return 0;
}