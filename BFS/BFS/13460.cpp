#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x, y, dir, cnt;
}pos;

pair<int, int> sttRed, sttBlue;
int N, M;
char map[10][10];

bool redballFirst(int nextDir, int x, int y) {
	
	if (nextDir == 0) { // west
		for (int i = 0; i < M; i++) {
			if (map[x][i] == 'R') return true;
			else if (map[x][i] == 'B') return false;
		}
	}
	else if (nextDir == 1) { // east
		for (int i = M-1; i >=0; i--) {
			if (map[x][i] == 'R') return true;
			else if (map[x][i] == 'B') return false;
		}
	}
	else if (nextDir == 2) { // north
		for (int i = 0; i < N; i++) {
			if (map[i][y] == 'R') return true;
			else if (map[i][y] == 'B') return false;
		}
	}
	else { // south
		for (int i = N-1; i >= 0; i--) {
			if (map[i][y] == 'R') return true;
			else if (map[i][y] == 'B') return false;
		}
	}
}

pair<int,int> move(int ballX, int ballY, int dir) {
	if (dir == 0) {
		for (int i = 1; i < M; i++) {
		
			if (map[ballX][ballY - i] != '.' && map[ballX][ballY-i] != 'O') {
				char temp = map[ballX][ballY - i + 1];
				map[ballX][ballY - i + 1] = map[ballX][ballY];
				map[ballX][ballY] = temp;
				
				return make_pair(ballX, ballY - i + 1);
			}
			else if (map[ballX][ballY - i] == 'O') {
				return make_pair(ballX, ballY - i);
			}
		}
	}
	else if (dir == 1) {

		for (int i = 1; i < M; i++) {
			if (map[ballX][ballY + i] != '.' && map[ballX][ballY+i] != 'O') {
				char temp = map[ballX][ballY + i - 1];
				map[ballX][ballY + i - 1] = map[ballX][ballY];
				map[ballX][ballY] = temp;
				
				return make_pair(ballX, ballY + i - 1);
			}
			else if (map[ballX][ballY + i] == 'O') {
				return make_pair(ballX, ballY + i);
			}
		}

	}
	else if (dir == 2) {

		for (int i = 1; i < N; i++) {
			if (map[ballX - i][ballY] != '.' && map[ballX-i][ballY] != 'O') {
				char temp = map[ballX - i + 1][ballY];
				map[ballX - i+1][ballY] = map[ballX][ballY];
				map[ballX][ballY] = temp;
				return make_pair(ballX - i + 1, ballY);
			}
			else if (map[ballX - i][ballY] == 'O') {
				return make_pair(ballX - i, ballY);
			}
		}
	}
	else if (dir == 3) {

		for (int i = 1; i < N; i++) {
			if (map[ballX + i][ballY] != '.' && map[ballX+i][ballY] != 'O') {
				char temp = map[ballX + i - 1][ballY];
				map[ballX + i - 1][ballY] = map[ballX][ballY];
				map[ballX][ballY] = temp;
				return  make_pair(ballX + i - 1, ballY);
			}
			else if (map[ballX + i][ballY] == 'O') {
				return make_pair(ballX + i, ballY);
			}
		}
	}

}

int solve() {

	queue <pos> r; queue <pos> b;
	r.push({ sttRed.first , sttRed.second, 0, 0 });
	b.push({ sttBlue.first, sttBlue.second, 0, 0 });

	while (r.front().cnt <= 10) {

		int rcurX = r.front().x;
		int rcurY = r.front().y;
		int bcurX = b.front().x;
		int bcurY = b.front().y;
		int dir = r.front().dir;
		int cnt = r.front().cnt;

		r.pop(); b.pop();

		if (map[rcurX][rcurY] == 'O') return cnt;

		for (int i = 0; i < 4; i++) {
			if (cnt > 0 && (dir == i || (dir == 0 && i == 1) || (dir==1 && i==0) 
				|| (dir==2 && i==3) || (dir==3 && i ==2) )) continue;
			
			map[rcurX][rcurY] = 'R';
			map[bcurX][bcurY] = 'B';

			pair<int, int> pr; pair<int, int> pb;

			if (redballFirst(i, rcurX, rcurY)) {

				pr = move(rcurX, rcurY, i);
				if (map[pr.first][pr.second] == 'O')
					map[rcurX][rcurY] = '.';
				pb = move(bcurX, bcurY, i);
				
				if (map[pr.first][pr.second] != 'O' && map[pb.first][pb.second] =='O') { // ÆÄ
					map[pr.first][pr.second] = '.';
					map[bcurX][bcurY] = '.';
					continue;
				}
				else if (map[pr.first][pr.second] == 'O' && map[pb.first][pb.second] == 'O') { // »¡ , ÆÄ 
					map[bcurX][bcurY] = '.';
					continue;
				} 
				else if(map[pr.first][pr.second] == 'O' && map[pb.first][pb.second] != 'O') { // »¡
					map[pb.first][pb.second] = '.';
				}
				else { // µÑ´Ù µé¾î°¡Áö ¾ÊÀ½
					map[pr.first][pr.second] = '.';
					map[pb.first][pb.second] = '.';
					
				}
				
				r.push({ pr.first, pr.second, i,  cnt + 1 });
				b.push({ pb.first, pb.second, i , cnt + 1 });
			
			}
			else {
				pb = move(bcurX, bcurY, i);
				if (map[pb.first][pb.second] == 'O') { // ÆÄ
					map[bcurX][bcurY] = '.';
					map[rcurX][rcurY] = '.';
					continue;
				}
				pr = move(rcurX, rcurY, i);

				if (map[pr.first][pr.second] == 'O' && map[pb.first][pb.second] != 'O') { // »¡
					map[rcurX][rcurY] = '.';
					map[pb.first][pb.second] = '.';
				}
				else {
					map[pr.first][pr.second] = '.';
					map[pb.first][pb.second] = '.';
				}
				r.push({ pr.first, pr.second, i,  cnt + 1 });
				b.push({ pb.first, pb.second, i , cnt + 1 });
				
			}

		}

	}

	return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string input;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j];
			if (map[i][j] == 'R') {
				sttRed.first = i;
				sttRed.second = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				sttBlue.first = i;
				sttBlue.second = j;
				map[i][j] = '.';
			}
		}
	}

	cout << solve() << "\n";

	return 0;
}