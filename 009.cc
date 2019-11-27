#include <iostream>

int main(int argc, char *argv[]) {  
	for(long long i = 0; i < 1000; i++) {
		for(long long j = 0; j < 1000; j++) {
			if(i * i + j * j == (1000 - i - j) * (1000 - i - j)) {
				std::cout << i * j * (1000-i-j) * 1LL << std::endl;
				//return 0;
			}
		}
	}
	return 0;
}