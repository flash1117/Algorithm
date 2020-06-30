#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NUM 1000001

char input[MAX_NUM];

int main() {
	int ret = 0;
	fgets(input, MAX_NUM, stdin);
	
	char* tok = strtok(input, " ");
	while (tok != nullptr) {
		if (tok[0] == '\n' ) break;
		tok = strtok(nullptr, " ");
		ret++;
	}

	printf("%d\n", ret);

	return 0;
}