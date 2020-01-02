#include <iostream>
#include <vector>

using namespace std;
int cube[6][3][3];


vector <int> rot;

void initCube() {

	int startValue = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = startValue++;
			}
		}
	}
}

void print(int caseNum, int P) {

	cout << "#" << caseNum << " ";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[P - 1][i][j] << " ";
			}
		}
	cout << "\n";
}

void rotateCube(int order) {

	// 0-A 1-B 2-C 3-D 4-E 5-F

	if (order == 1 || order == 2 || order == 3) {

		if (order == 1) {

			int temp = cube[4][0][2];
			cube[4][0][2] = cube[4][2][2];
			cube[4][2][2] = cube[4][2][0];
			cube[4][2][0] = cube[4][0][0];
			cube[4][0][0] = temp;

			temp = cube[4][0][1];
			cube[4][0][1] = cube[4][1][2];
			cube[4][1][2] = cube[4][2][1];
			cube[4][2][1] = cube[4][1][0];
			cube[4][1][0] = temp;

		}
		else if (order == 3) {
			int temp = cube[5][0][2];
			cube[5][0][2] = cube[5][0][0];
			cube[5][0][0] = cube[5][2][0];
			cube[5][2][0] = cube[5][2][2];
			cube[5][2][2] = temp;

			temp = cube[5][0][1];
			cube[5][0][1] = cube[5][1][0];
			cube[5][1][0] = cube[5][2][1];
			cube[5][2][1] = cube[5][1][2];
			cube[5][1][2] = temp;
		}

		for (int i = 0; i < 3; i++) {
			int temp = cube[0][i][order-1];
			cube[0][i][order-1] = cube[1][i][order-1];
			cube[1][i][order-1] = cube[2][i][order-1];
			cube[2][i][order-1] = cube[3][i][order-1];
			cube[3][i][order-1] = temp;

		}
	}
	else if (order == 4 || order == 5 || order == 6) {
		order -= 4;

		if (order == 0) {

			int temp = cube[4][0][2];
			cube[4][0][2] = cube[4][0][0];
			cube[4][0][0] = cube[4][2][0];
			cube[4][2][0] = cube[4][2][2];
			cube[4][2][2] = temp;

			temp = cube[4][0][1];
			cube[4][0][1] = cube[4][1][0];
			cube[4][1][0] = cube[4][2][1];
			cube[4][2][1] = cube[4][1][2];
			cube[4][1][2] = temp;
		}
		else if (order == 2) {

			int temp = cube[5][0][2];
			cube[5][0][2] = cube[5][2][2];
			cube[5][2][2] = cube[5][2][0];
			cube[5][2][0] = cube[5][0][0];
			cube[5][0][0] = temp;

			temp = cube[5][0][1];
			cube[5][0][1] = cube[5][1][2];
			cube[5][1][2] = cube[5][2][1];
			cube[5][2][1] = cube[5][1][0];
			cube[5][1][0] = temp;

		}
		for (int i = 0; i < 3; i++) {
			int temp = cube[0][i][order];
			cube[0][i][order] = cube[3][i][order];
			cube[3][i][order] = cube[2][i][order];
			cube[2][i][order] = cube[1][i][order];
			cube[1][i][order] = temp;
		}
	}
	else if (order == 7 || order == 8 || order == 9) {
		order -= 7;
		
		if (order == 0) {
			int temp = cube[0][0][2];
			cube[0][0][2] = cube[0][0][0];
			cube[0][0][0] = cube[0][2][0];
			cube[0][2][0] = cube[0][2][2];
			cube[0][2][2] = temp;

			temp = cube[0][0][1];
			cube[0][0][1] = cube[0][1][0];
			cube[0][1][0] = cube[0][2][1];
			cube[0][2][1] = cube[0][1][2];
			cube[0][1][2] = temp;
		}
		else if (order == 2) {

			int temp = cube[2][0][0];
			cube[2][0][0] = cube[2][0][2];
			cube[2][0][2] = cube[2][2][2];
			cube[2][2][2] = cube[2][2][0];
			cube[2][2][0] = temp;

			temp = cube[2][0][1];
			cube[2][0][1] = cube[2][1][2];
			cube[2][1][2] = cube[2][2][1];
			cube[2][2][1] = cube[2][1][0];
			cube[2][1][0] = temp;

		}

		for (int i = 0; i < 3; i++) {
			int temp = cube[4][order][i];
			cube[4][order][i] = cube[1][order][i];
			cube[1][order][i] = cube[5][order][i];
			cube[5][order][i] = cube[3][2 - order][2 - i];
			cube[3][2 - order][2 - i] = temp;

		}
		

	}
	else if (order == 10 || order == 11 || order == 12) {
		order -= 10;

		if (order == 0) {
			int temp = cube[0][0][2];
			cube[0][0][2] = cube[0][2][2];
			cube[0][2][2] = cube[0][2][0];
			cube[0][2][0] = cube[0][0][0];
			cube[0][0][0] = temp;

			temp = cube[0][0][1];
			cube[0][0][1] = cube[0][1][2];
			cube[0][1][2] = cube[0][2][1];
			cube[0][2][1] = cube[0][1][0];
			cube[0][1][0] = temp;
		}
		else if (order == 2) {

			int temp = cube[2][0][0];
			cube[2][0][0] = cube[2][2][0];
			cube[2][2][0] = cube[2][2][2];
			cube[2][2][2] = cube[2][0][2];
			cube[2][0][2] = temp;

			temp = cube[2][0][1];
			cube[2][0][1] = cube[2][1][0];
			cube[2][1][0] = cube[2][2][1];
			cube[2][2][1] = cube[2][1][2];
			cube[2][1][2] = temp;

		}
		for (int i = 0; i < 3; i++) {
			int temp = cube[4][order][i];
			cube[4][order][i] = cube[3][2 - order][2 - i];
			cube[3][2 - order][2 - i] = cube[5][order][i];
			cube[5][order][i] = cube[1][order][i];
			cube[1][order][i] = temp;
		}
	}

}
int main() {

	int T, M, P, caseNum = 1;
	cin >> T;
	while (T--) {

		initCube();
		int temp;
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> temp;
			rot.push_back(temp);
		}
		cin >> P;

		for (int i = 0; i < rot.size(); i++)
			rotateCube(rot[i]);

		print(caseNum++, P);
		rot.clear();
	}



	return 0;
}