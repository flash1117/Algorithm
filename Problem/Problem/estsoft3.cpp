#include <iostream>
#include <vector>

using namespace std;

vector<int> A = { 3,4,5,3,7};

bool isPretty()
{
	bool mode = true;
	if (A[0] > A[1]) mode = false; 
	else if (A[0] < A[1]); 
	else return false;

	if (mode) { // 다음 수가 커지는 것으로 시작
		for (int i = 1; i < A.size(); i+=2) {
			
			if (i > 0 && A[i - 1] >= A[i]) return false;
			if (i + 1 < A.size() && A[i + 1] >= A[i]) return false;
		}
	}

	else { // 다음 수가 작아지는 것으로 시작
		for (int i = 1; i < A.size(); i += 2) {

			if (i > 0 && A[i - 1] <= A[i]) return false;
			if (i + 1 < A.size() && A[i + 1] <= A[i]) return false;
		}
	}

	return true;
}
int solution() {

	bool _pretty = isPretty();
	if (_pretty) return 0;
	else {

		int cnt = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; i < A.size(); i++) {
				bool mode = true;
				if (i == 0) {
					
					if (A[1] > A[2]) mode = false;
					else if (A[1] < A[2]);
					else break;

					if (j == i) continue;
					else {
						if (mode) { // 다음 수가 커지는 것으로 시작
							for (int k = 0; k < A.size(); k += 2) {

								if (k - 1 != i && k > 0 && A[k - 1] >= A[k]) break;
								else if (k - 1 == i && k > 1 && A[k - 2] >= A[k]) break;
								if (k + 1 != i && k + 1 < A.size() && A[k + 1] >= A[k]) break;
								else if (k + 1 == i && k + 2 < A.size() && A[k + 2] >= A[k]) break;

								if (k == A.size() - 1) cnt++;
							}
						}
						else { // 다음 수가 작아지는 것으로 시작
							for (int k = 0; k < A.size(); k += 2) {

								if (k - 1 != i && k > 0 && A[k - 1] <= A[k]) break;
								else if (k - 1 == i && k > 1 && A[k - 2] <= A[k]) break;
								if (k + 1 != i && k + 1 < A.size() && A[k + 1] <= A[k]) break;
								else if (k + 1 == i && k + 2 < A.size() && A[k + 2] <= A[k]) break;

								if (k == A.size() - 1) cnt++;
							}
						}
					}

				}
				else if (i == 1) {
					
					if (A[0] > A[2]) mode = false;
					else if (A[0] < A[2]);
					else break;

					if (j == i) continue;
					else {
						if (mode) { // 다음 수가 커지는 것으로 시작
							for (int k = 0; k < A.size(); k += 2) {

								if (k - 1 != i && k > 0 && A[k - 1] >= A[k]) break;
								else if (k - 1 == i && k > 1 && A[k - 2] >= A[k]) break;
								if (k + 1 != i && k + 1 < A.size() && A[k + 1] >= A[k]) break;
								else if (k + 1 == i && k + 2 < A.size() && A[k + 2] >= A[k]) break;

								if (k == A.size() - 1) cnt++;
							}
						}
						else { // 다음 수가 작아지는 것으로 시작
							for (int k = 0; k < A.size(); k += 2) {

								if (k - 1 != i && k > 0 && A[k - 1] <= A[k]) break;
								else if (k - 1 == i && k > 1 && A[k - 2] <= A[k]) break;
								if (k + 1 != i && k + 1 < A.size() && A[k + 1] <= A[k]) break;
								else if (k + 1 == i && k + 2 < A.size() && A[k + 2] <= A[k]) break;

								if (k == A.size() - 1) cnt++;
							}
						}
					}

				}
				else {

					if (A[0] > A[1]) mode = false;
					else if (A[0] < A[1]);
					else break;

					if (j == i) continue;
					else {
						if (mode) { // 다음 수가 커지는 것으로 시작
							for (int k = 0; k < A.size(); k += 2) {

								if (k - 1 != i && k > 0 && A[k - 1] >= A[k]) break;
								else if (k - 1 == i && k > 1 && A[k - 2] >= A[k]) break;
								if (k+1 != i && k + 1 < A.size() && A[k + 1] >= A[k]) break;
								else if (k + 1 == i && k + 2 < A.size() && A[k + 2] >= A[k]) break;

								if (k == A.size() - 1) cnt++;
							}
						}
						else { // 다음 수가 작아지는 것으로 시작
							for (int k = 0; k < A.size(); k += 2) {

								if (k - 1 != i && k > 0 && A[k - 1] <= A[k]) break;
								else if (k - 1 == i && k > 1 && A[k - 2] <= A[k]) break;
								if (k + 1 != i && k + 1 < A.size() && A[k + 1] <= A[k]) break;
								else if (k + 1 == i && k + 2 < A.size() && A[k + 2] <= A[k]) break;

								if (k == A.size() - 1) cnt++;
							}
						}
					}

				}



			}

		}

		if (cnt == 0) return -1;
		else return cnt;
	}
}

int main() {

	int ret = solution();
	cout << ret;

	return 0;
}