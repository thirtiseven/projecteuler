#include <iostream>

int main(int argc, char *argv[]) {  
	int ans = 0;
	for(int i = 3; i < 1000; i += 3) {
		ans += i;
	}
	for(int i = 5; i < 1000; i += 5) {
		ans += i;
	}
	for(int i = 15; i < 1000; i+=15) {
		ans -= i;
	}
	std::cout << ans << std::endl;
	return 0;
}