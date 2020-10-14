#include <iostream>
#include <algorithm>

using ll = long long;

ll dp[103][11], ans = 0;

const int x = 100;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	dp[0][0] = 0;
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= 9; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < x; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= j; k++) {
//				std::cout << "\'";
//				if (dp[i-1][k]) {
//					std::cout << ".";
//				}
				dp[i][j] += dp[i-1][k];
			}
			ans += dp[i][j];
			std::cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << ans << '\n';
		}
	}
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= 9; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < x; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] += dp[i-1][k];
			}
			ans += dp[i][j];
			std::cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << ans << '\n';
		}
	}
	ans -= (x-2)*9;
	std::cout << ans << '\n';
}