#include <iostream>

int main(int argc, char *argv[]) {  
	int sum = 0, ans = 0;
	for (int i = 12; i <= 1000; i++) {
		int tot = 0;
		for (int j = 1; j < i-2; j++) {
			for (int k = j; i-j-k >= k; k++) {
				if (j*j+k*k == (i-j-k)*(i-j-k)) {
					tot++;
				}
			}
		}
		if (tot > sum) {
			sum = tot;
			ans = i;
		}
	}
	std::cout << ans << '\n';
}