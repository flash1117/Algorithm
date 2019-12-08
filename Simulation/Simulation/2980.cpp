#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef struct {
	int D, R, G;
}Traffic;

typedef struct {
	int c, time, index;
}People;

int N, L;
vector <Traffic> Light;


int solve() {

	queue <People> q;
	q.push({ 0,0,0 });
	int time = 0;

	while (!q.empty()) {

		int cur = q.front().c;
		time = q.front().time;
		int index = q.front().index;

		cout << cur << " " << time << endl;

		q.pop();
		if (cur == L) return time;
		if (index == Light.size()) continue;

		if (cur == Light[index].D) {
			if ((time % (Light[index].G + Light[index].R)) - Light[index].R <= 0) {
				time += abs((Light[index].G + Light[index].R) - Light[index].R);
				cur++;
				time++;
				index++;
			}
			else {
				time++;
				cur++;
				index++;
			}
			q.push({ cur,time,index });
		}
		else {
			cur++;
			time++;
			q.push({ cur,time,index });
		}

	}
	return time;
}
int main() {

	int d, r, g;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> d >> r >> g;
		Light.push_back({ d,r,g });
	}

	cout << solve() << "\n";
	return 0;
}