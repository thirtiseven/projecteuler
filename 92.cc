#include <iostream>

bool check(int x) {
	int res;
	while (1) {
		res = 0;
		while (x) {
			res += (x%10)*(x%10);
			x /= 10;
		}
		x = res;
		if (x == 1) {
			return false;
		} else if (x == 89) {
			return true;
		}
	}
}

int main(int argc, char *argv[]) {  
	int ans = 0;
	for (int i = 1; i <= 10000000; i++) {
		if (check(i)) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}