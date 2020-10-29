#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	int od, src, dst;
}Order;

int N, M;
int numSet[1000001];

int findSet(int x) {

	if (x == numSet[x]) return x;
	else return findSet(numSet[x]);
}

void initNumSet() {

	for (int i = 1; i <= N; i++)
		numSet[i] = i;

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	initNumSet();
	for (int i = 0; i < M; i++) {

		Order _order;

		cin >> _order.od >> _order.src >> _order.dst;

		switch (_order.od)
		{
		case 0 :
		{
			int a = findSet(_order.src);
			int b = findSet(_order.dst);

			if (a > b) numSet[a] = b;
			else numSet[b] = a;

			break;
		}
		case 1:
		{
			int a = findSet(_order.src);
			int b = findSet(_order.dst);

			if (a == b) cout << "YES\n";
			else cout << "NO\n";
			break;
		}
		default:
			break;
		}
	}

	return 0;
}