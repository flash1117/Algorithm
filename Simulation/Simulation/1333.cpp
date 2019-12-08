#include <iostream>
#include <queue>

using namespace std;

int N, L, D;

int solve() {

	int timeCnt = 0;
	queue <pair<int, bool>> q;
	q.push({ L,false });

	while (N) {

		timeCnt++;
		int qCur = q.front().first;
		bool qState = q.front().second;

		q.pop(); 

		if (!qState) {
			if (qCur > 0) q.push({ qCur - 1, false });
			else {
				q.push({ 5,true });
				if (timeCnt % D == 0) return timeCnt + 1;
			}
		}
		else {
			if (timeCnt % D == 0) return timeCnt;

			if (qCur > 0) q.push({ qCur - 1, true });
			else {
				q.push({ L,false });
				N--;
			}
		}

	}
	
	return N*L+(N-1)*5;
}
int main() {

	cin >> N >> L >> D;
	cout << solve() << "\n";

	return 0;
}