#include <iostream>
#include <vector>

using namespace std;

int dice[10];
int sum;
vector<int> dice1;
vector<int> dice2;
vector<int> dice3;
vector<int> dice4;

int roads[] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40 };
int firstCrossroad[] = { 13,16,19,25,30,35,40 };
int secondCrossroad[] = { 22,24,25,30,35,40 };
int finalCrossroad[] = { 28,27,26,25,30,35,40 };

void printDice() {

	for (int i = 0; i < dice1.size(); i++) {

		cout << dice1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < dice2.size(); i++) {

		cout << dice2[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < dice3.size(); i++) {

		cout << dice3[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < dice4.size(); i++) {

		cout << dice4[i] << " ";
	}
	cout << endl;

}

int isBlue(int diceValue) {

	if (diceValue == 5) return 1;
	else if (diceValue == 10) return 2;
	else if (diceValue == 15) return 3;
	return 0;
}

pair<int,int> findInArray(int index) {

	for (int i = 0; i < dice1.size(); i++) {

		if (dice1[i] == index) return make_pair(1, i);
	}

	for (int i = 0; i < dice2.size(); i++) {
		if (dice2[i] == index) return make_pair(2, i);
	}

	for (int i = 0; i < dice3.size(); i++) {

		if (dice3[i] == index) return make_pair(3, i);
	}

	for (int i = 0; i < dice4.size(); i++) {

		if (dice4[i] == index) return make_pair(4, i);
	}

	return make_pair(-1,-1);
}

void comb(int depth) {

	if (depth > 9) {
		pair<int, int> pos1 = { 0, 0 }, pos2 = { 0, 0 }, pos3 = { 0, 0 }, pos4 = { 0, 0 };
		int _sum = 0;
		bool isCorrect = true;

		for (int i = 0; i < 10; i++) {
			pair<int, int> loc = findInArray(i);

			switch (loc.first)
			{
			case 1: {
				
				if (pos1.second == 0) {
					pos1.second = isBlue(pos1.first + dice[i]);
					
					if (pos1.second > 0) pos1.first = 0;




				}
				else if(pos1.second == 1) {
					int nextPos = pos1.first + dice[i] - 1;
					if (nextPos > 6) pos1.first += dice[i] - 1;
					else {
						_sum += firstCrossroad[nextPos];
						pos1.first += dice[i] - 1;
					}
					
					
				}
				else if (pos1.second == 2) {

					int nextPos = pos1.first + dice[i] - 1;
					if (nextPos > 5) pos1.first += dice[i] - 1;
					else {
						_sum += secondCrossroad[nextPos];
						pos1.first += dice[i] - 1;
					}

				}
				else if (pos1.second == 3) {

					int nextPos = pos1.first + dice[i] - 1;
					if (nextPos > 6) pos1.first += dice[i] - 1;
					else {
						_sum += finalCrossroad[nextPos];
						pos1.first += dice[i] - 1;
					}

				}

				pos1.first += dice1[loc.second];

				break;
			}
			case 2: {

				break;
			}
			case 3: {

				break;
			}
			case 4: {

				break;
			}
			default:
				break;
			}
		}




	
		if (isCorrect) sum = sum > _sum ? sum : _sum;

		return;
	}

	dice1.push_back(depth);
	comb(depth + 1);
	dice1.pop_back();
	dice2.push_back(depth);
	comb(depth + 1);
	dice2.pop_back();
	dice3.push_back(depth);
	comb(depth + 1);
	dice3.pop_back();
	dice4.push_back(depth);
	comb(depth + 1);
	dice4.pop_back();
	return;
}


int main() {

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	comb(0);


	return 0;
}