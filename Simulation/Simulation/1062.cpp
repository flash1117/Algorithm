#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector <string> input;
vector <pair<int, char>> vec;

int solve() {

	// ������ �����ľ� �ϴ� ���� a n t i c
	if (K < 5) return 0;
	else K -= 5;

	int ret = 0, temp = 0;

	for (int i = 0; i <= ('z' - 'a'); i++)
		vec.push_back(make_pair(0, 'a' + i));

	for (int i = 0; i <= K; i++) { // �߰� ���ڿ� ����

		for (int j = 0; j < input.size(); j++) { // �־��� Test Case ��ȸ
			temp = 0;
			if (input[j].length() - 8 == 0 && i == 0) ret++; // �ʱ갪 ����
			else if (input[j].length() - 8 <= i){

				

			}
		}

	}


	return ret;
}


int main() {

	string temp;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		input.push_back(temp);
	}

	cout << solve << "\n";
	return 0;
}