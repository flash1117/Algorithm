#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector <ll> vec;


ll getDistFromZero(ll sum) {

	if (sum < 0) return -sum;
	else return sum;
}

void solve() {
	ll left=0, right=0;
	ll _min = 2000000001;
	for (int i = 0; i < N-1; i++) {

		ll sum = vec[i] + vec[i + 1];

		if (getDistFromZero(sum) < getDistFromZero(_min)) {
			_min = sum;
			left = vec[i];
			right = vec[i + 1];

		}

	}
	
	if (left < right)
		cout << left << " " << right << "\n";
	else cout << right << " " << left << "\n";

	return; 
}


bool compare(ll a, ll b) {

	ll absoluteA = getDistFromZero(a);
	ll absoluteB = getDistFromZero(b);

	if (absoluteA != absoluteB)
		return absoluteA < absoluteB;
	else return a < b;
}


void print() {

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end(), compare);
//	print();
	solve();

	return 0;
}