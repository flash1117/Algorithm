#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vec;
int N, M;

int main() {

	int T, input, cnt =0;
	cin >> T;
	while (T--) {

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> input;
			vec.push_back(input);
		}

		int temp = vec[M];
		if (N != 1) {
			for (int i = M + 1;i < vec.size(); i++) {
				if (vec[i] == temp) cnt++;
			}
			if (cnt == 0) cnt = 1;
			sort(vec.begin(), vec.end(), greater<int>());
			for (int i = 0; i < vec.size(); i++) {
			
				if (vec[i] == temp) break;
					cnt++;
			}

			cout << cnt << endl;
		}
		else
			cout << 1 << endl;
		
		vec.clear();
		cnt = 0;
	}


	return 0;
}