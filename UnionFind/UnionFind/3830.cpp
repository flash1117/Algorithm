#include <iostream>

using namespace std;
const int MAX = 100001;
typedef long long ll;

int N, M, Root[MAX];
ll dist[MAX];
// Find ����
int Update(int x) {
	if (Root[x] == x) return x;
	int R = Update(Root[x]);
	// Root ���� ��� ������Ʈ 
	dist[x] += dist[Root[x]];
	return Root[x] = R;
}
// Union ����
void merge(int a, int b, int diff) {
	int aRoot = Root[a];
	int bRoot = Root[b];
	if (aRoot == bRoot) return;
	// aRoot ���� b �� ��ġ
	int NewD = dist[a] + diff;
	// bRoot ���� b �� ��ġ
	int OriginD = dist[b];
	// bRoot �� aRoot ���� ������
	Root[bRoot] = aRoot;
	// ���� bRoot ���� aRoot�� �Ÿ�
	dist[bRoot] = NewD - OriginD;
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; ++i) {
			Root[i] = i;
			dist[i] = 0;
		}
		for (int i = 0; i < M; ++i) {
			char ch;
			int a, b, w;
			cin >> ch >> a >> b;
			Update(a);
			Update(b);
			if (ch == '!') {
				cin >> w;
				merge(a, b, w);
			}
			else {
				if (Root[a] == Root[b]) cout << dist[b] - dist[a] << '\n';
				else cout << "UNKNOWN" << '\n';
			}
		}
	}
	return 0;
}