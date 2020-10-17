#include <iostream>

using namespace std;


typedef struct {

	int memorySize, codeSize, inputSize;

}Interpreter;

int T;

int main() {

	cin >> T;
	while (T--) {
		string brainFuck;
		string programInput;
		Interpreter inter;
		cin >> inter.memorySize >> inter.codeSize >> inter.inputSize;
		cin >> brainFuck;
		cin >> programInput;


	}

	return 0;
}