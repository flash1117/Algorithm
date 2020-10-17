#include <iostream>

using namespace std;

typedef struct {

	int index, state, curValue;

}State;

int maxSum;
int dice[10];
int map[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40 };
int map1[] = { 10,13,16,19,25,30,35,40 };
int map2[] = { 20,22,24,25,30,35,40 };
int map3[] = { 30,28,27,26,25,30,35,40 };

int setState(int num) {

	if (num == 10) return 1;
	else if (num == 20) return 2;
	else if (num == 30) return 3;

	return 0;
}


void solve(int depth, int sum, State s1, State s2, State s3, State s4) {
	
	if (depth >= 10) {

		maxSum = maxSum > sum ? maxSum : sum;
		return;
	}

	int curDice = dice[depth];
	int nextValue;

	if (s1.state == 0) {
		if (s1.index + curDice <= 20)
			nextValue = map[s1.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 10) {

			if ((s2.index == 0 && s2.state == 1) || (s3.index == 0 && s3.state == 1) || (s4.index == 0 && s4.state == 1));
			else solve(depth + 1, sum + nextValue, { 0, 1, 10 }, s2, s3, s4);
		}
		else if(nextValue == 20){
			if ((s2.index == 0 && s2.state == 2) || (s3.index == 0 && s3.state == 2) || (s4.index == 0 && s4.state == 2));
			else solve(depth + 1, sum + nextValue, { 0, 2, 20 }, s2, s3, s4);
		}
		else if (nextValue == 30) {
			if ((s2.index == 0 && s2.state == 3) || (s3.index == 0 && s3.state == 3) || (s4.index == 0 && s4.state == 3));
			else solve(depth + 1, sum + nextValue, { 0, 3, 30 }, s2, s3, s4);
		}
		else if(nextValue == 0){
			if(s1.index <= 20)
				solve(depth + 1, sum, { 21, 0, 0 }, s2, s3, s4);
		}
		else {
			if ((s2.index == s1.index + curDice && s2.state == s1.state) || (s3.index == s1.index + curDice && s3.state == s1.state) || (s4.index == s1.index + curDice && s4.state == s1.state));
			else if (nextValue == 40 && (s2.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s2.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));

			else solve(depth + 1, sum + nextValue, { s1.index + curDice, 0, nextValue }, s2, s3, s4);
		}


	}
	else if (s1.state == 1) {
		if (s1.index + curDice <= 7)
			nextValue = map1[s1.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s1.index <= 7)
				solve(depth + 1, sum, { 8, s1.state, 0 }, s2, s3, s4);
		}
		else {
			if ((s2.index == s1.index + curDice && s2.state == s1.state) || (s3.index == s1.index + curDice && s3.state == s1.state) || (s4.index == s1.index + curDice && s4.state == s1.state));
			else if (nextValue == 40 && (s2.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s2.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s2.curValue == 35 || s3.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s2.curValue == 30 && s2.index > 0) || (s3.curValue == 30 && s3.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, { s1.index + curDice, s1.state, nextValue }, s2, s3, s4);
		}

	}
	else if (s1.state == 2) {

		if (s1.index + curDice <= 6)
			nextValue = map2[s1.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s1.index <= 6)
				solve(depth + 1, sum, { 8, s1.state, 0 }, s2, s3, s4);
		}
		else {
			if ((s2.index == s1.index + curDice && s2.state == s1.state) || (s3.index == s1.index + curDice && s3.state == s1.state) || (s4.index == s1.index + curDice && s4.state == s1.state));
			else if (nextValue == 40 && (s2.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s2.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s2.curValue == 35 || s3.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s2.curValue == 30 && s2.index > 0) || (s3.curValue == 30 && s3.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, { s1.index + curDice, s1.state, nextValue }, s2, s3, s4);
		}

	}
	else if (s1.state == 3) {
		if (s1.index + curDice <= 7)
			nextValue = map3[s1.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s1.index<=7)
				solve(depth + 1, sum, { 8, s1.state, 0 }, s2, s3, s4);
		}
		else {
			if ((s2.index == s1.index + curDice && s2.state == s1.state) || (s3.index == s1.index + curDice && s3.state == s1.state) || (s4.index == s1.index + curDice && s4.state == s1.state));
			else if (nextValue == 40 && (s2.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s2.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s2.curValue == 35 || s3.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s2.curValue == 30 && s2.index > 0) || (s3.curValue == 30 && s3.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, { s1.index + curDice, s1.state, nextValue }, s2, s3, s4);
		}

	}

	/// state2

	if (s2.state == 0) {
		if (s2.index + curDice <= 20)
			nextValue = map[s2.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 10) {
			if ((s1.index == 0 && s1.state == 1) || (s3.index == 0 && s3.state == 1) || (s4.index == 0 && s4.state == 1));
			else solve(depth + 1, sum + nextValue, s1, { 0, 1, 10 }, s3, s4);
		}
		else if (nextValue == 20) {
			if ((s1.index == 0 && s1.state == 2) || (s3.index == 0 && s3.state == 2) || (s4.index == 0 && s4.state == 2));
			else solve(depth + 1, sum + nextValue, s1, { 0, 2, 20 }, s3, s4);
		}
		else if (nextValue == 30) {
			if ((s1.index == 0 && s1.state == 3) || (s3.index == 0 && s3.state == 3) || (s4.index == 0 && s4.state == 3));
			else solve(depth + 1, sum + nextValue, s1, { 0, 3, 30 }, s3, s4);
		}
		else if (nextValue == 0) {
			if(s2.index <= 20)
				solve(depth + 1, sum, s1, { 21, 0, 0 }, s3, s4);
		}
		else {
			if ((s1.index == s2.index + curDice && s2.state == s1.state) || (s3.index == s2.index + curDice && s3.state == s2.state) || (s4.index == s2.index + curDice && s4.state == s2.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else solve(depth + 1, sum + nextValue,s1, { s2.index + curDice, 0, nextValue }, s3, s4);
		}


	}
	else if (s2.state == 1) {
		if (s2.index + curDice <= 7)
			nextValue = map1[s2.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s2.index <= 7)
				solve(depth + 1, sum, s1, { 8, s2.state, 0 }, s3, s4);
		}
		else {
			if ((s1.index == s2.index + curDice && s2.state == s1.state) || (s3.index == s2.index + curDice && s3.state == s2.state) || (s4.index == s2.index + curDice && s4.state == s2.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s3.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s3.curValue == 30 && s3.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue,s1, { s2.index + curDice, s2.state, nextValue }, s3, s4);
		}

	}
	else if (s2.state == 2) {

		if (s2.index + curDice <= 6)
			nextValue = map2[s2.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s2.index<=6)
				solve(depth + 1, sum, s1, { 8, s2.state, 0 }, s3, s4);
		}
		else {
			if ((s1.index == s2.index + curDice && s2.state == s1.state) || (s3.index == s2.index + curDice && s3.state == s2.state) || (s4.index == s2.index + curDice && s4.state == s2.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s3.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s3.curValue == 30 && s3.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue,s1 , { s2.index + curDice, s2.state, nextValue }, s3, s4);
		}

	}
	else if (s2.state == 3) {
		if (s2.index + curDice <= 7)
			nextValue = map3[s2.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s2.index <= 7)
				solve(depth + 1, sum,s1, { 8, s2.state, 0 }, s3, s4);
		}
		else {
			if ((s1.index == s2.index + curDice && s2.state == s1.state) || (s3.index == s2.index + curDice && s3.state == s2.state) || (s4.index == s2.index + curDice && s4.state == s2.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s3.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s3.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s3.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s3.curValue == 30 && s3.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, s1, { s2.index + curDice, s2.state, nextValue }, s3, s4);
		}

	}


	/// state3

	if (s3.state == 0) {
		if (s3.index + curDice <= 20)
			nextValue = map[s3.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 10) {
			if ((s1.index == 0 && s1.state == 1) || (s2.index == 0 && s2.state == 1) || (s4.index == 0 && s4.state == 1));
			else solve(depth + 1, sum + nextValue, s1, s2, { 0, 1, 10 }, s4);
		}
		else if (nextValue == 20) {
			if ((s1.index == 0 && s1.state == 2) || (s2.index == 0 && s2.state == 2) || (s4.index == 0 && s4.state == 2));
			else solve(depth + 1, sum + nextValue, s1,s2, { 0, 2, 20 }, s4);
		}
		else if (nextValue == 30) {
			if ((s1.index == 0 && s1.state == 3) || (s2.index == 0 && s2.state == 3) || (s4.index == 0 && s4.state == 3));
			else solve(depth + 1, sum + nextValue, s1,s2 , { 0, 3, 30 }, s4);
		}
		else if (nextValue == 0) {
			if(s3.index <= 20)
				solve(depth + 1, sum, s1,s2 , { 21, 0, 0 }, s4);
		}
		else {
			if ((s1.index == s3.index + curDice && s3.state == s1.state) || (s2.index == s3.index + curDice && s3.state == s2.state) || (s4.index == s3.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s4.curValue == 25));
			else solve(depth + 1, sum + nextValue, s1,s2 , { s3.index + curDice, 0, nextValue }, s4);
		}


	}
	else if (s3.state == 1) {
		if (s3.index + curDice <= 7)
			nextValue = map1[s3.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s3.index <= 7)
				solve(depth + 1, sum, s1, s2, { 8, s3.state, 0 }, s4);
		}
		else {
			if ((s1.index == s3.index + curDice && s3.state == s1.state) || (s2.index == s3.index + curDice && s3.state == s2.state) || (s4.index == s3.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s2.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s2.curValue == 30 && s2.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, s1, s2, { s3.index + curDice, s3.state, nextValue }, s4);
		}

	}
	else if (s3.state == 2) {

		if (s3.index + curDice <= 6)
			nextValue = map2[s3.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s3.index <= 6)
				solve(depth + 1, sum, s1,s2, { 8, s3.state, 0 }, s4);
		}
		else {
			if ((s1.index == s3.index + curDice && s3.state == s1.state) || (s2.index == s3.index + curDice && s3.state == s2.state) || (s4.index == s3.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s2.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s2.curValue == 30 && s2.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, s1, s2, { s3.index + curDice, s3.state, nextValue }, s4);
		}

	}
	else if (s3.state == 3) {
		if (s3.index + curDice <= 7)
			nextValue = map3[s3.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s3.index <= 7)
				solve(depth + 1, sum, s1,s2, { 8, s3.state, 0 }, s4);
		}
		else {
			if ((s1.index == s3.index + curDice && s3.state == s1.state) || (s2.index == s3.index + curDice && s3.state == s2.state) || (s4.index == s3.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s4.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s4.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s2.curValue == 35 || s4.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s2.curValue == 30 && s2.index > 0) || (s4.curValue == 30 && s4.index > 0)));
			else solve(depth + 1, sum + nextValue, s1,s2, { s3.index + curDice, s3.state, nextValue }, s4);
		}

	}

	/// state4

	if (s4.state == 0) {
		if (s4.index + curDice <= 20)
			nextValue = map[s4.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 10) {
			if ((s1.index == 0 && s1.state == 1) || (s2.index == 0 && s2.state == 1) || (s3.index == 0 && s3.state == 1));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { 0, 1, 10 });
		}
		else if (nextValue == 20) {
			if ((s1.index == 0 && s1.state == 2) || (s2.index == 0 && s2.state == 2) || (s3.index == 0 && s3.state == 2));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { 0, 2, 20 });
		}
		else if (nextValue == 30) {
			if ((s1.index == 0 && s1.state == 3) || (s2.index == 0 && s2.state == 3) || (s3.index == 0 && s3.state == 3));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { 0, 3, 30 });
		}
		else if (nextValue == 0) {
			if(s4.index <= 20)
				solve(depth + 1, sum, s1, s2, s3, { 21, 0, 0 });
		}
		else {
			if ((s1.index == s4.index + curDice && s4.state == s1.state) || (s2.index == s4.index + curDice && s4.state == s2.state) || (s3.index == s4.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s3.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s3.curValue == 25));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { s4.index + curDice, 0, nextValue });
		}


	}
	else if (s4.state == 1) {
		if (s4.index + curDice <= 7)
			nextValue = map1[s4.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s4.index <= 7)
				solve(depth + 1, sum, s1, s2, s3, { 8, s4.state, 0 });
		}
		else {
			if ((s1.index == s4.index + curDice && s4.state == s1.state) || (s2.index == s4.index + curDice && s4.state == s2.state) || (s3.index == s4.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s3.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s3.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s2.curValue == 35 || s3.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s2.curValue == 30 && s2.index > 0) || (s3.curValue == 30 && s3.index > 0)));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { s4.index + curDice, s4.state, nextValue });
		}

	}
	else if (s4.state == 2) {

		if (s4.index + curDice <= 6)
			nextValue = map2[s4.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s4.index <= 6)
				solve(depth + 1, sum, s1, s2, s3, { 8, s4.state, 0 });
		}
		else {
			if ((s1.index == s4.index + curDice && s4.state == s1.state) || (s2.index == s4.index + curDice && s4.state == s2.state) || (s3.index == s4.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s3.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s3.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s2.curValue == 35 || s3.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s2.curValue == 30 && s2.index > 0) || (s3.curValue == 30 && s3.index > 0)));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { s4.index + curDice, s4.state, nextValue });
		}

	}
	else if (s4.state == 3) {
		if (s4.index + curDice <= 7)
			nextValue = map3[s4.index + curDice];
		else
			nextValue = 0;

		if (nextValue == 0) {
			if(s4.index <= 7)
				solve(depth + 1, sum, s1, s2, s3, { 8, s4.state, 0 });
		}
		else {
			if ((s1.index == s4.index + curDice && s4.state == s1.state) || (s2.index == s4.index + curDice && s4.state == s2.state) || (s3.index == s4.index + curDice && s4.state == s3.state));
			else if (nextValue == 40 && (s1.curValue == 40 || s2.curValue == 40 || s3.curValue == 40));
			else if (nextValue == 25 && (s1.curValue == 25 || s2.curValue == 25 || s3.curValue == 25));
			else if (nextValue == 35 && (s1.curValue == 35 || s2.curValue == 35 || s3.curValue == 35));
			else if (nextValue == 30 && ((s1.curValue == 30 && s1.index > 0) || (s2.curValue == 30 && s2.index > 0) || (s3.curValue == 30 && s3.index > 0)));
			else solve(depth + 1, sum + nextValue, s1, s2, s3, { s4.index + curDice, s4.state, nextValue });
		}

	}

	return;
}

int main() {


	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	State s = { 0,0,0 };
	solve(0, 0, s, s, s, s);


	cout << maxSum << "\n";
	return 0;
}