#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	int ans = 0;
	double cur = 0, a, b;
	for (int i = 1; i <= 1000; i++) {
		std::cin >> a >> b;
		if (b*std::log(a) > cur) {
			cur = b*std::log(a);
			ans = i;
		}
	}
	std::cout << ans;
}