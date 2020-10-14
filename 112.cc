#include <iostream>
#include <algorithm>
#include <string>

int check(int x) {
	std::string s = std::to_string(x);
	bool dec = 0, inc = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] < s[i-1]) {
			dec = 1;
		} else if (s[i] > s[i-1]) {
			inc = 1;
		}
	}
	if (dec and inc) {
		return 1;
	}
	return 0;
}

const int upper = 10000000;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int bouncy = 0, notb = 0;
	for (int i = 1; i <= upper; i++) {
		if (check(i)) {
			bouncy++;
		} else {
			notb++;
		}
		if (bouncy >= notb*99) {
			std::cout << i << '\n';
			break;
		}
//		std::cout << i << ' ' << bouncy << ' ' << notb << '\n';
	}
	std::cout << bouncy << ' ' << notb << '\n';
}