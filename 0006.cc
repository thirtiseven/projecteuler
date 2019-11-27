#include <iostream>

int main(int argc, char *argv[]) {  
	long long ans1 = 0, ans2 = 0;
	for(int i = 0; i <= 100; i++) {
		ans1 += i;
		ans2 += i * i;
	}
	ans1 *= ans1;
	std::cout << ans1 - ans2;
	return 0;
}