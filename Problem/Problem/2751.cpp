#include <iostream>
using namespace std;
//ÄüÁ¤·Ä
int n, cnt, quick[10000001];

void quickSort(int i, int j)
{
	if (i >= j) return;
	int pivot = quick[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right)
	{
		while (quick[left] < pivot) left++;
		while (quick[right] > pivot) right--;
		if (left <= right)
		{
			swap(quick[left], quick[right]);
			left++; right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> quick[i];

	quickSort(0, n - 1);

	for (int j = 0; j < n; j++) // Ãâ·Â
		cout << quick[j] << "\n";

	return 0;
}