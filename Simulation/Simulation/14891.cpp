#include <iostream>

using namespace std;

int Gear[8][4];
int pos[101], dir[101],K;

// N ���� 0, S�� 1

void moveGear(int position ,int direction) {
	
	int buf = Gear[0][position];
	
	if (direction == -1) { // �ݽð� ����

		Gear[0][position] = Gear[1][position];
		Gear[1][position] = Gear[2][position];
		Gear[2][position] = Gear[3][position];
		Gear[3][position] = Gear[4][position];
		Gear[4][position] = Gear[5][position];
		Gear[5][position] = Gear[6][position];
		Gear[6][position] = Gear[7][position];
		Gear[7][position] = buf;

	}
	else if (direction == 1) { // �ð� ����

		Gear[0][position] = Gear[7][position];
		Gear[7][position] = Gear[6][position];
		Gear[6][position] = Gear[5][position];
		Gear[5][position] = Gear[4][position];
		Gear[4][position] = Gear[3][position];
		Gear[3][position] = Gear[2][position];
		Gear[2][position] = Gear[1][position];
		Gear[1][position] = buf;

	}

}

bool stateCheck() { // �ֺ� ��Ϲ��� ���� üũ


	return true;
}

void solve() {

	for (int i = 0; i < K; i++) {

		moveGear(pos[i] - 1, dir[i]); 



	}


}


int main() {

	int temp;

	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 8; j++) 
			cin >> Gear[j][i];
			
	cin >> K;

	for (int i = 0; i < K; i++)
		cin >> pos[i] >> dir[i];

	solve();
	return 0;
}