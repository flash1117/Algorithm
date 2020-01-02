#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {

	int country, g, s, c;
}pos;

vector <pos> input;
int N, K;

bool compare(pos &src, pos &dst) {

	if(src.g != dst.g)
		return src.g > dst.g;
	else {

		if (src.s != dst.s) return src.s > dst.s;
		else return src.c > dst.c;
	}
	
}

int main() {

	cin >> N >> K;
	pos temp;
	for (int i = 0; i < N; i++) {

		cin >> temp.country >> temp.g >> temp.s >> temp.c;
		input.push_back(temp);
	}

	sort(input.begin(), input.end(), compare);
	for (int i = 0; i < input.size(); i++) {

		if (input[i].country == K) {

			if (i > 0) {
				for (int j = i - 1; j >= 0; j--) {
					if (input[j].g == input[i].g && input[j].s == input[i].s && input[i].c == input[j].c);
					else {
						cout << j + 2 << "\n";
						break;
					}

				}
			}
			else cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}