#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
vector <int> vec;
bool visited[101];
int start;

vector <int> process;
vector <int> ret;
void DFS(int x)
{
	if (visited[x] && x != start) {

		for (int i = 1; i < process.size(); i++) {
			if(process[i] != start)
				visited[process[i]] = false;
		}
		return;
	}
	if (x == vec[x - 1] && !visited[x] && x== start) {
		ret.push_back(x);
		return;
	}
		
	if (!visited[x])
		process.push_back(x);
	
	visited[x] = true;

	if (vec[x - 1] == start) {
		for (int i = 0; i < process.size(); i++) {
			ret.push_back(process[i]);
		}
			
		
		return;
	}

	DFS(vec[x - 1]);

}

void Init() {

	for (int i = 0; i < process.size(); i++)
		process.pop_back();

}

int main() {

	memset(visited, false, sizeof(visited));
	int input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);

	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			start = i;
			DFS(i);
			Init();
		}
			

	}
	
	cout << endl << ret.size() << endl;

	sort(ret.begin(), ret.end());

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
	return 0;
}