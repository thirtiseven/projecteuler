#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 100000;

int rad(int x) {
	int res = 1;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			x /= i;
			res *= i;
		}
		while (x % i) {
			x /= i;
		}
	}
	if (x) {
		res *= x;
	}
	return res;
}

std::vector<std::pair<int, int>> a;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	for (int i = 1; i <= maxn; i++) {
		a.push_back(std::make_pair(rad(i), i));
	}
	std::sort(a.begin(), a.end());
	std::cout << a[9999].second << '\n';
}