#include <iostream>
#include <vector>

using namespace std;

vector<int> v[401];
vector<int> rv[401];
bool visited[401];


bool DFS(int h1, int h2,int c) {
	if (visited[h2]) return 0;
	if (h1 == h2) return 1;
//	cout << "µµÂøÁ¡ : "<<h2 << " " << c << endl;
	visited[h2] = 1;
	bool a;
	if (!c)
	for (int i = 0; i < v[h2].size(); i++) {
		a = DFS(h1, v[h2][i], c);
		if (a == 1) return 1;
	}
	else 
	for (int i = 0; i < rv[h2].size(); i++) {
		a = DFS(h1, rv[h2][i], c);
		if (a==1) return 1;
	}
	return 0;
}

void Init(int n) {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

int main() {
	int n, k,input1,input2,s;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> input1 >> input2;
		v[input1].push_back(input2);
		rv[input2].push_back(input1);

	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> input1 >> input2;

		if (DFS(input1, input2,0)) cout << 1 << endl;
		else {
			Init(n);
			cout << -DFS(input1, input2,1) << endl;
		}
		Init(n);
	}

	return 0;
}