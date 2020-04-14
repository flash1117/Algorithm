#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string answer_sheet, vector<string> sheets) {
	int answer = 0, sheetLen = answer_sheet.length();
	int doubtNum = 0, continueNum = 0, maxContinueNum = 0;
	bool st = false;
	for (int i = 0; i < sheets.size() - 1; i++) {

		for (int k = 1; i+k < sheets.size(); k++) {

			doubtNum = 0;
			continueNum = 0;
			maxContinueNum = 0;
			st = false;

			for (int j = 0; j < sheetLen; j++) {
				if (sheets[i][j] == sheets[i + k][j] && sheets[i][j] != answer_sheet[j]) {
					doubtNum++;
					continueNum++;
					
					maxContinueNum = maxContinueNum > continueNum ? maxContinueNum : continueNum;
				}
				else {
					st = false;
					continueNum = 0;
				}
			}
			cout << doubtNum << " " << maxContinueNum << endl;
			answer = (doubtNum + maxContinueNum * maxContinueNum) > answer ? (doubtNum + maxContinueNum * maxContinueNum) : answer;
			
		}

		
	}

	return answer;
}


int main() {
	string answer_sheet = "4132315142";
		
	vector<string> sheets;
	sheets.push_back("3241523133");
	sheets.push_back("4121314445");
	sheets.push_back("3243523133");
	sheets.push_back("4433325251");
	sheets.push_back("2412313253");

	int temp = solution(answer_sheet, sheets);
	cout << temp << endl;


	return 0;
}