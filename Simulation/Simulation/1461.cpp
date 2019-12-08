#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ret=0;
vector <int> Plus;
vector <int> Minus;

void solve() {

	sort(Plus.begin(), Plus.end());
	sort(Minus.begin(), Minus.end());

	int temp = 0, temp2 = 0;

	/*
	for (int i = 0; i < M;i++) {
		if (!Plus.empty()) {
			temp += Plus.back();
		}
		if (!Minus.empty()) {
			temp2 += Minus.back();
		}
	}
	*/
	
	if (!Plus.empty() && !Minus.empty()) {
		temp = Plus.back();
		temp2 = Minus.back();
	}
	else if (Plus.empty()) temp2 = Minus.back();
	else temp = Plus.back();

	if (temp2 > temp) {
		ret += Minus.back();
		for (int i = 0; i < M; i++) {
			if (!Minus.empty()) Minus.pop_back();
		}
	}
	else {
		ret += Plus.back();
		for (int i = 0; i < M; i++) {
			if (!Plus.empty()) Plus.pop_back();
		}
	}

	while (!Plus.empty()) {
		ret += 2 * Plus.back();
		for (int i = 0; i < M; i++) {
			if(!Plus.empty()) Plus.pop_back();
		}
	}
	while (!Minus.empty()) {
		ret += 2 * Minus.back();
		for (int i = 0; i < M; i++) {
			if(!Minus.empty()) Minus.pop_back();
		}
	}
}

int main() {

	int temp = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp >= 0) Plus.push_back(temp);
		else Minus.push_back(temp * (-1));
	}
	solve();
	cout << ret << "\n";
	return 0;
}