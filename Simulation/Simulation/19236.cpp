#include <iostream>
#include <vector>

using namespace std;

typedef struct {

	int x, y, dir;
}Pos;

int map[5][5];

int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,0,-1,-1,-1,0,1,1,1 };

vector<Pos> fish[17];

void fishSwap() {



}

bool isBoundary(int x, int y) {
	if (x < 1 || y < 1 || x>4 || y>4) return false;
	return true;
}


int main() {




	return 0;
}