#include <iostream>
#include <string>

std::string s = "0";

int main(int argc, char *argv[]) { 
	int cur = 1; 
	while (s.length() <= 1000000) {
		s += std::to_string(cur);
		cur++;
	}
	std::cout << s[1] << ' ' << s[10] << ' ' << s[100] << ' ' << s[1000] << ' ' << '\n';
	int ans = 1;
	ans *= (s[1]-'0');
	ans *= (s[10]-'0');
	ans *= (s[100]-'0');
	ans *= (s[1000]-'0');
	ans *= (s[10000]-'0');
	ans *= (s[100000]-'0');
	ans *= (s[1000000]-'0');
	std::cout << ans << '\n';
}