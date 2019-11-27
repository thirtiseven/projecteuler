#include <iostream>
#include <cmath>

int factor(int n) {
	int temp, i, now, tot;
	temp = (int)((double)sqrt(n)+1);
	tot = 0;
	now = n;
	for (int i = 2; i <= temp; ++i) {
		if (now % i == 0) {
			tot++;
		}
		while (now % i == 0) {
			now/=i;
		}
	}
	if (now != 1) {
		tot++;
	}
	return tot;
}

const int upper = 1e6+4;

int num[upper];

int main(int argc, char *argv[]) {  
//	int x;
//	while (std::cin >> x) {
//		std::cout << factor(x) << '\n';
//	}
	for (int i = 647; i <= upper; i++) {
		num[i] = factor(i);
	}
	for (int i = 647; i <= upper-5; i++) {
		if (num[i] == 4 && num[i+1] == 4 && num[i+2] == 4 && num[i+3] == 4) {
			std::cout << i << '\n';
			break;
		}
	}
}