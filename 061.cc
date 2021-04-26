//WRONG
#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 123;

std::vector<std::pair<int, int>> g[maxn];

void init() {
	int x;
	for (int n = 1; n <= 100; n++) {
		x = n*(n+1)/2;
		if (x >= 1000 && x <= 9999) {
			g[x/100].push_back(std::make_pair(x%100, 1));
		}
		x = n*n;
		if (x >= 1000 && x <= 9999) {
			g[x/100].push_back(std::make_pair(x%100, 2));
		}
		x = n*(3*n-1)/2;
		if (x >= 1000 && x <= 9999) {
			g[x/100].push_back(std::make_pair(x%100, 4));
		}
		x = n*(2*n-1);
		if (x >= 1000 && x <= 9999) {
			g[x/100].push_back(std::make_pair(x%100, 8));
		}
		x = n*(5*n-3)/2;
		if (x >= 1000 && x <= 9999) {
			g[x/100].push_back(std::make_pair(x%100, 16));
		}
		x = n*(3*n-2);
		if (x >= 1000 && x <= 9999) {
			g[x/100].push_back(std::make_pair(x%100, 32));
		}
	}
}

void dfs(int now, int ori, int first_step, int tot) {
	std::cout << now << '\n';
	if (tot >= 64) {
		return;
	}
	if (now == ori && first_step == 0) {
	 	if (tot == 63) {
			std::cout << "Find!";
		}
	}
	for (auto it: g[now]) {
		if ((tot & it.second) == 0) {
			dfs(it.first, ori, 0, tot | it.second);
		}
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	init();
	for (int i = 10; i <= 99; i++) {
		std::cout << "number " << i << " : ";
		dfs(i, i, 1, 0);
		std::cout << "\n";
	}
}