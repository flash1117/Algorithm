#include <string>
#include <vector>

using namespace std;

int open1, open2, open3, open4;

int solution(string inputString) {
	int answer = 0;

	for (int i = 0; i < inputString.length(); i++) {

		if (inputString[i] == '(' || inputString[i] == ')') {
			if (inputString[i] == '(') {
				open1++;
				answer++;
			}
			else open1--;

			if (open1 < 0) return -1;
		}
		else if (inputString[i] == '{' || inputString[i] == '}') {
			if (inputString[i] == '{') {
				open2++;
				answer++;
			}
			else open2--;

			if (open2 < 0) return -1;
		}
		else if (inputString[i] == '[' || inputString[i] == ']') {
			if (inputString[i] == '[') {
				open3++;
				answer++;
			}
			else open3--;

			if (open3 < 0) return -1;
		}
		else if (inputString[i] == '<' || inputString[i] == '>') {
			if (inputString[i] == '<') {
				open4++;
				answer++;
			}
			else open4--;

			if (open4 < 0) return -1;
		}
	}
	if (open1 != 0 || open2 != 0 || open3 != 0 || open4 != 0) return -1;

	return answer;
}