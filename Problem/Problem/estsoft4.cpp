#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string, int>> emailList;

string S = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker";
string C = "Example";
string solution() { // S 는 이름, C는 회사이름
	string ret = "\"";
	string _name = "", _email = "";
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != ';') {
			_name += S[i];
		}
		else {
			string fName = "", lName = "";
			for (int j = 0; j < _name.length(); j++) {
				if (_name[j] == ' ') break;
				fName += _name[j];
			}
			
			for (int j = _name.length() - 1; j >= 0; j--) {
				if (_name[j] == ' ') break;
				lName = _name[j] + lName;
			}
			
			bool isExist = false;
			for (int j = 0; j < emailList.size(); j++) {
				if (emailList[j].first == lName + fName) {
					_email = "<"+lName + "_" + fName + to_string(emailList[j].second) + C+".com"+">";
					emailList[j].second++;
					isExist = true;
				} 
			}
			if (!isExist)  {

				_email = "<" + lName + "_" + fName + C +".com"+ ">";
				emailList.push_back({ lName + fName,1 });
			}
			ret += _name + " " + _email+"; ";
			_name = "";
			_email = "";
		}

	}
	string fName = "", lName = "";
	for (int j = 0; j < _name.length(); j++) {
		if (_name[j] == ' ') break;
		fName += _name[j];
	}

	for (int j = _name.length() - 1; j >= 0; j--) {
		if (_name[j] == ' ') break;
		lName = _name[j] + lName;
	}

	bool isExist = false;
	for (int j = 0; j < emailList.size(); j++) {
		if (emailList[j].first == lName + fName) {
			_email = "<" + lName + "_" + fName + to_string(emailList[j].second) + C+".com" + ">";
			emailList[j].second++;
			isExist = true;
		}
	}
	if (!isExist) { 
	
		_email = "<" + lName + "_" + fName + C+".com" + ">";
		emailList.push_back({ lName + fName,1 }); 
	}
	ret += _name + " " + _email + "\".";
	_name = "";
	_email = "";

	return ret;
}

int main() {

	string ret = solution();
	cout << ret << endl;
	return 0;
}