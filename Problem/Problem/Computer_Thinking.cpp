#include <iostream>
#include <string>

using namespace std;

bool isFaster(string a, string b) {

	for (int i = 0; i < a.length(); i++) {
		if (a[i] < b[i]) return true;
		else if (a[i] > b[i]) return false;
	}

	return false;
}


string a, b;

void comb(int depth, int cnt, int boundary, int purposeLen) {

	if (cnt == purposeLen) {



	}


	if (depth >= boundary) return;






}

int main() {


	string str = "ACABC";

	for (int i = 0; i < str.length(); i++) {

		
		for (int j = 1; j <= str.length(); j++) {

			string a = "";
			string b = "";





		}



	}


	return 0;
}