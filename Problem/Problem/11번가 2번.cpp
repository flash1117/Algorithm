#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


typedef struct {

	int x, y, z;
}TriangleSide;

bool isTriangle(TriangleSide tSideLen) {

	if (tSideLen.x + tSideLen.y <= tSideLen.z) return false;
	else if (tSideLen.x + tSideLen.z <= tSideLen.y) return false;
	else if (tSideLen.y + tSideLen.z <= tSideLen.x) return false;
	else if (tSideLen.x <= 0 || tSideLen.y <= 0 || tSideLen.z <= 0) return false;
	return true;
}

int solution(vector<int>& A) {

	int answer = -1;
	int arraySize = A.size();
	for (int i = 0; i < arraySize - 2; i++) {

		for (int j = i + 1; j < arraySize - 1; j++) {
			for (int k = j + 1; k < arraySize; k++) {
				TriangleSide t = { A[i], A[j], A[k] };
				bool triangleCheck = isTriangle(t);

				if (triangleCheck) {
					int triangleLenSum = A[i] + A[j] + A[k];
					answer = max(answer, triangleLenSum);
				}
			}
		}
	}

	return answer;


}

int main() {

	vector<int> A = { 10, 2, 5, 1, 8, 20 };
	cout << solution(A);

	return 0;
}