#include <iostream>
#include <algorithm>

//012   
//021   
//102   
//120   
//201   
//210

#include <string>

std::string now = "0123456789";

int main(int argc, char *argv[]) {  
	int cnt = 1;
	while (cnt < 1000000) {
		std::next_permutation(now.begin(), now.end());
		cnt++;
//		std::cout << cnt << ' ' << now << '\n';
	}
	std::cout << now;
}