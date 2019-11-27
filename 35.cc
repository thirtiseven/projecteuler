#include <iostream>
#include <cmath>

const int maxn = 1000000;
bool prime_or_not[maxn];

int main(int argc, char *argv[]) {  
	for (int i = 2; i <= int(sqrt(maxn)); i++) {
		if (!prime_or_not[i]) {
	    	for (int j = i * i; j <= maxn; j = j+i) {
				prime_or_not[j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (!prime_or_not[i]) {
			std::string s = std::to_string(i);
			int len = s.length()-1;
			bool yes = 1;
			for (int i = 0; i < len; i++) {
				std::string c = s.substr(len, 1);
				s.erase(len);
				s = c + s;
				if (prime_or_not[std::stoi(s)]) {
					yes = 0;
					break;
				}
			}
			if (yes) {
				std::cout << i << ' ';
				ans ++;
			}
		}
	}
	std::cout << ans << '\n';
}