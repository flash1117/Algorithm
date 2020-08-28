#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getCorrect(string u, string v) {

	int left = 0;
	int right = 0;
	bool correct = true;
	string _u = "";
	string _v = "";

	if (u == "") return "";

	for (int i = 0; i < u.length(); i++) {
		if (u[i] == '(') left++;
		else right++;

		if (right > left) correct = false;
		_u += u[i];
		if (left > 0 && right > 0 && left == right) {
			for (int j = i + 1; j < u.length(); j++)
				_v += u[j];
			break;
		}
	}

	if (correct) {
		// u가 올바른 문자열
		return _u + getCorrect(_v, "");
	}
	else {
		string ret = "(" + getCorrect(_v, "") + ")";
		for (int i = 1; i < _u.length() - 1; i++) {
			if (_u[i] == '(') ret += ")";
			else ret += "(";
		}
		return ret;
	}

}


string solution(string p) {
	string answer = "";

	answer = getCorrect(p, "");

	return answer;
}


int main() {

	string t = solution(")(");
	cout << t;

	return 0;
}