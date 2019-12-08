#include <iostream>
#include <string>

using namespace std;

char Array[1000];

void setString() {
	Array[' '] = ' ';
	Array['1'] = '`';
	for (int i = '2'; i <= '9'; i++)
		Array[i] = i - 1;
	Array['0'] = '9';
	Array['-'] = '0';
	Array['='] = '-';
	Array['W'] = 'Q';
	Array['E'] = 'W';
	Array['R'] = 'E';
	Array['T'] = 'R';
	Array['Y'] = 'T';
	Array['U'] = 'Y';
	Array['I'] = 'U';
	Array['O'] = 'I';
	Array['P'] = 'O';
	Array['['] = 'P';
	Array[']'] = '[';
	Array['\\'] = ']';
	Array['S'] = 'A';
	Array['D'] = 'S';
	Array['F'] = 'D';
	Array['G'] = 'F';
	Array['H'] = 'G';
	Array['J'] = 'H';
	Array['K'] = 'J';
	Array['L'] = 'K';
	Array[';'] = 'L';
	Array['\''] = ';';
	Array['X'] = 'Z';
	Array['C'] = 'X';
	Array['V'] = 'C';
	Array['B'] = 'V';
	Array['N'] = 'B';
	Array['M'] = 'N';
	Array[','] = 'M';
	Array['.'] = ',';
	Array['/'] = '.';
}

int main()
{
	
	string temp;

	setString();
	while (getline(cin, temp)) {

		for (int i = 0; i < temp.length(); i++) {
			temp[i] = Array[temp[i]];
		}
		cout << temp;
	}
	return 0;
}

