#include <iostream>
#include <string>
#include <algorithm>
#include <set>

int main(int argc, char *argv[]) {  
	std::string s = "123456789";
	std::set<int> ans;
	int res = 0;
	while (std::next_permutation(s.begin(), s.end())) {
		for (int i = 1; i < 8; i++) {
			for (int j = 1; i+j < 9; j++) {
				if (std::stoi(s.substr(0, i)) * std::stoi(s.substr(i, j)) == std::stoi(s.substr(i+j))) {
					std::cout << s << ' ';
					std::cout << std::stoi(s.substr(0, i)) << ' ' << std::stoi(s.substr(i, j)) << " " << std::stoi(s.substr(i+j)) << '\n';
					ans.insert(std::stoi(s.substr(i+j)));
				}
			}
		}
	}
	for (auto it: ans) {
		std::cout << it << '\n';
		res += it;
	}
	std::cout << res << '\n';
}