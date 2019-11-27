#include <iostream>
#include <string>
#include <fstream>
std::ifstream fin ("p22.txt"); 

int main(int argc, char *argv[]) {  
	std::string s[10000];
	for (int i = 0;i < 5162;i++) {
		fin >> s[i];
	}
	std::sort(s, s+5162);
	long long ans = 0;
	for (long long i = 0; i < 5162; i++) {
		long long temp = 0;
		for (int j = 0; j < s[i].length(); j++) {
			temp += (long long)(s[i][j]-'A'+1);
		}
		ans += (i+1LL)*temp;
	}
	std::cout << ans << '\n';
}