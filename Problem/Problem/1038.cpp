#include <iostream>

using namespace std;

int n;
 
int getDigit(int num) {

	if (num == 0) return 1;
	int ret = 0;
	
	while (num) {

		num /= 10;
		ret++;
	}

	return ret;
}

bool isDiminish(long long num) {

	int digit = getDigit(num);
	long long prev = -1;

	for (int i = 0; i < digit; i++) {

		if (prev == -1) prev = num % 10;
		else {

			long long r = num % 10;
			if (r > prev) prev = r;
			else {

				return false;
			}
		}

		num /= 10;
	}


	return true;
}

int main() {

	cin >> n;
	int cnt = 10;
	if (n <= 10) cout << n << "\n";
	else if(n < 1012){
		long long i = 11;
		while (1) {

			bool check = isDiminish(i);
			
			if (check) {
				cnt++;
			//	cout << cnt << " " << i << "\n";
				
			}

			if (cnt == n) {
				cout << i << "\n";
				return 0;
			}
			i++;	
			if(cnt == 846) i = 6543210;
			else if (cnt == 966) i = 76543210;
		}

	}
	else {

		switch (n)
		{
		case 1012: {
			cout << 876543210 << "\n";
			break;
		}
		case 1013: {
			cout << 976543210 << "\n";
			break;
		}
		case 1014: {
			cout << 986543210 << "\n";
			break;
		}
		case 1015: {
			cout << 987543210 << "\n";
			break;
		}
		case 1016: {
			cout << 987643210 << "\n";
			break;

		}
		case 1017: {
			cout << 987653210 << "\n";
			break;

		}
		case 1018: {
			cout << 987654210 << "\n";
			break;

		}
		case 1019: {
			cout << 987654310 << "\n";
			break;

		}
		case 1020: {
			cout << 987654320 << "\n";
			break;

		}
		case 1021: {
			cout << 987654321 << "\n";
			break;

		}
		case 1022: {
			cout << 9876543210 << "\n";
			break;

		}

		default:
			cout << -1 << "\n";
			break;
		}

	}

	return 0;
}
