#include <iostream>

using namespace std;

int A, B, C, maxLen;
pair <int, int> a, b, c;
int sum[101];

void print() {

	for (int i = 1; i <= maxLen; i++) {
		cout << sum[i] << " ";
	}
	cout << endl;
}

int solve() {

	int ret = 0;

	for (int i = a.first; i < a.second; i++)
		sum[i]++;
	
	for (int i= b.first; i < b.second; i++)
		sum[i]++;

	for (int i = c.first; i < c.second; i++)
		sum[i]++;

	for (int i = 1; i < maxLen; i++)
	{
		if (sum[i] == 1) ret += sum[i] * A;
		else if (sum[i] == 2) ret += sum[i] * B;
		else if (sum[i] == 3) ret += sum[i] * C;
	}

	return ret;
}

int main() {

	int src, dst;
	cin >> A >> B >> C;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	maxLen = (a.second > b.second) ? a.second:b.second ;
	maxLen = (maxLen > c.second) ? maxLen : c.second;

	cout << solve() << "\n";

	return 0;
}