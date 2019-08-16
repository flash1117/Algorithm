#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Endl "\n"

vector <int> hobit;
int Ary[7];
bool isAnswer;
void solve(int depth , int cnt) {

	if (depth == 7) {
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum += Ary[i];
		
		if (sum == 100) {
			for (int i = 0; i < 7; i++)
				cout << Ary[i] << Endl;
			isAnswer = true;
		}
			
		return;
	}

	for (int i = depth; i < hobit.size(); i++) {


		Ary[depth] = hobit[i];
//		if(Ary[depth] > Ary[depth-1] || depth == 0)
		solve(depth + 1, cnt + 1);
		if (isAnswer) return;
	}
}

int main() {

	int input;
	for (int i = 0; i < 9; i++) {

		cin >> input;
		hobit.push_back(input);
		
	}

	sort(hobit.begin(), hobit.end());
	solve(0,0);

	return 0;
}