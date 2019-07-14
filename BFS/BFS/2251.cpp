#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C;

typedef struct {

	int x, y, z;
}bottle;

vector <int> ret;
void BFS() {

	queue <bottle> q;
	q.push({ 0,0,C });

	while (!q.empty()) {
		bottle cur = q.front();
		q.pop();

		if(cur.z > 0)
			ret.push_back(cur.z);

		if (A + B > C) {
			q.push({ A,C - A,0 });

		}
		else { // A + B < C


		}




	}
	

}

int main() {

	cin >> A >> B >> C;

	return 0;
}