#include <iostream>
#include <vector>

using namespace std;

typedef struct {

	int x, d, k;
}Rotate;

int N, M, T;
Rotate rot[51];
vector<int> circle[51];

int getSum() {

	int sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			sum += circle[i][j];
		}
	}

	return sum;
}


int removeSameNum() {

	vector<pair<int, int>> pos;

	for (int i = 1; i <= N; i++) {

		int nextUp, nextDown, nextLeft, nextRight;

		if (i < N) nextUp = i + 1;
		else nextUp = -1;

		if (i > 1) nextDown = i - 1;
		else nextDown = -1;

		for (int j = 0; j < M; j++) {

		

			if (j == 0) nextLeft = M - 1;
			else nextLeft = j - 1;

			if (j == M - 1) nextRight = 0;
			else nextRight = j + 1;


			if (circle[i][j] == circle[i][nextLeft]) {
				pos.push_back(make_pair(i, nextLeft));
			}
			if (circle[i][j] == circle[i][nextRight]) {
				pos.push_back(make_pair(i, nextRight));
			}
			if (nextUp != -1 && circle[i][j] == circle[nextUp][j]) {
				pos.push_back(make_pair(nextUp, j));
			}
			if (nextDown != -1 && circle[i][j] == circle[nextDown][j]) {
				pos.push_back(make_pair(nextDown, j));
			}	
		}
	}

	if (pos.empty()) return -1;
	bool state = false;
	for (int i = 0; i < pos.size(); i++) {
		if (circle[pos[i].first][pos[i].second] != 0) {
			circle[pos[i].first][pos[i].second] = 0;
			state = true;
		}
			
	}

	if(state) return 1;
	return -1;
}



void rotateCircle(int circleIndex ,int dir, int k) {

	int _circle[50];

	if (dir == 1) { // left

		for (int i = M - 1; i >= 0; i--) {

			if (i - k < 0) {
				_circle[M - k + i] = circle[circleIndex][i];
			}
			else {
				_circle[i - k] = circle[circleIndex][i];
			}
		}

		for (int i = 0; i < M; i++)
			circle[circleIndex][i] = _circle[i];

	}
	else {

		for (int i = 0; i < M; i++) {

			if (i + k > M - 1) {
				_circle[i + k - (M - 1) - 1] = circle[circleIndex][i];
			}
			else {

				_circle[i + k] = circle[circleIndex][i];
			}

		}

		for (int i = 0; i < M; i++)
			circle[circleIndex][i] = _circle[i];

	}

	return;
}


void changeByAverage() {

	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {

			if (circle[i][j] != 0) {
				cnt++;
				sum += circle[i][j];
			}
		}
	}

	double avg = (double)sum / (double)cnt;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {

			if (circle[i][j] != 0 && (double)circle[i][j] < avg) {
				circle[i][j]++;
			}
			else if ((double)circle[i][j] > avg) {
				circle[i][j]--;
			}
		}
	}


	return;
}

void print() {
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		cout <<i<< "번째 : ";
		for (int j = 0; j < M; j++) {
			cout << circle[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void solve() {

	for (int i = 1; i <= T; i++) {

		int curX = rot[i].x;
		int dir = rot[i].d; // dir is 0 -> right , dir is 1 -> left
		int moveCnt = rot[i].k;

		for (int j = 1; curX * j <= N; j++) {

			rotateCircle(curX * j, dir, moveCnt);

		}
//		cout << "회전\n";
//		print();
		if (removeSameNum() == -1) {

			changeByAverage();
		}
//		cout << "중복제거\n";
//		print();
	}

	cout << getSum() << "\n";

	return;
}


int main() {

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {

		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			circle[i].push_back(input);

		}

	}
	for (int i = 1; i <= T; i++) {
		cin >> rot[i].x >> rot[i].d >> rot[i].k;
	}

	solve();

	return 0;
}