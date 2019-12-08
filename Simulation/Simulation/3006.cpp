#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> vec;

void solve() {

	pair<int, int> pos = { 0,N - 1 };
	for (int i = 0; i < N; i++) {
		int index = 0;
		int cnt = 0;

		if (i % 2 == 0) {
			for (int j = 0; j < N; j++)
			{
				if (vec[j] == pos.first + 1)
				{
					index = j;
					break;
				}
			}
			for (int j = index; j > pos.first; j--) {
				int temp = 0;
				vec[j-1] = temp;
				vec[j - 1] = vec[j];
				vec[j] = temp;
				cnt++;
				
			}
			pos.first++;
			cout << cnt << "\n";
		}
		else {
			for (int j = 0; j < N; j++)
			{
				if (vec[j] == pos.second + 1)
				{
					index = j;
					break;
				}
			}
			for (int j = index; j < pos.second; j++) {
				int temp = 0;
				vec[j + 1] = temp;
				vec[j + 1] = vec[j];
				vec[j] = temp;
				cnt++;
			}
			pos.second--;
			cout << cnt << "\n";
		}
	}

}

int main() {

	int temp = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		vec.push_back(temp);
	}


	solve();
	return 0;
}