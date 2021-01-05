
#include <algorithm>

const int VALID_NUMBER_SIZE = 1000000 + 1;
int accessCount[VALID_NUMBER_SIZE];

int solution(vector<int>& A) {

	int answer = 0;

	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); i++) {
		if (accessCount[A[i]] > 1) continue;
		else {
			accessCount[A[i]]++;
			answer++;
		}
	}

	if (A.size() > 1 && A.back() == A[A.size() - 2]) return answer - 1;
	return answer;
}
