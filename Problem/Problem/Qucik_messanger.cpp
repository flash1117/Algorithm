#include <iostream>
#include <vector>

using namespace std;

bool letter[200001];
vector <pair<long long, long long>> prince;
vector <pair<long long, long long>> princess;

int solve() {

	for (int i = 0; i < prince.size(); i++) {
	
		for (int j = 0; j < princess.size(); j++) {
			if (!letter[j + 1]) {
				if (prince[i].first == princess[j].first || prince[i].second == princess[j].second)
					letter[j + 1] = true;
			}
		}

		if (letter[i + 1]) return i + 1;
	}

	return -1;
}

void midNodePush(pair<long long, long long> pos, bool sex)
{

	if (sex) {

		while (1) {
			if (prince.back() == pos) break;

			int prevX = prince.back().first;
			int prevY = prince.back().second;

			if (prevX == pos.first && prevY != pos.second) {
				if (prevY > pos.second)
					prince.push_back({ prevX, --prevY });
				else prince.push_back({ prevX, ++prevY });
			}
			else if (prevX != pos.first && prevY == pos.second) {
				if (prevX > pos.first) prince.push_back({ --prevX, prevY });
				else prince.push_back({ ++prevX, prevY });
			}
			else {

				if (prevX > pos.first && prevY > pos.second) prince.push_back({ --prevX, --prevY });
				else if (prevX > pos.first && prevY < pos.second) prince.push_back({ --prevX , ++prevY });
				else if (prevX < pos.first && prevY > pos.second) prince.push_back({ ++prevX , --prevY });
				else prince.push_back({ ++prevX , ++prevY });

			}
		}
	}
	else {
		while (1) {
			if (princess.back() == pos) break;

			int prevX = princess.back().first;
			int prevY = princess.back().second;

			if (prevX == pos.first && prevY != pos.second) {
				if (prevY > pos.second)
					princess.push_back({ prevX, --prevY });
				else princess.push_back({ prevX, ++prevY });
			}
			else if (prevX != pos.first && prevY == pos.second) {
				if (prevX > pos.first) princess.push_back({ --prevX, prevY });
				else princess.push_back({ ++prevX, prevY });
			}
			else {

				if (prevX > pos.first && prevY > pos.second) princess.push_back({ --prevX, --prevY });
				else if (prevX > pos.first && prevY < pos.second) princess.push_back({ --prevX , ++prevY });
				else if (prevX < pos.first && prevY > pos.second) princess.push_back({ ++prevX , --prevY });
				else princess.push_back({ ++prevX , ++prevY });

			}
		}
	}

}

int main() {

	int T, N, caseNum = 1;
	cin >> T;
	while (T--) {

		pair<long long, long long> pos;
		cin >> N;
		for (int i = 0; i < N + 1; i++) {
			cin >> pos.first >> pos.second;

			if (i == 0) prince.push_back(pos);
			else { midNodePush(pos, true); }
		}
		for (int i = 0; i < N + 1; i++) {
			cin >> pos.first >> pos.second;
			if (i == 0) princess.push_back(pos);
			else { midNodePush(pos, false); }
		}

		cout << "#" << caseNum++ << " " << solve() << "\n";

		for (int i = 0; i < princess.size(); i++) letter[i + 1] = false;
		prince.clear();
		princess.clear();
	}
	return 0;
}
