#include <iostream>

long long m[82][8];

long long dp[82][82];

int main(int argc, char *argv[]) { 
	for (int i = 1; i <= 80; i++) {
		for (int j = 1; j <= 80; j++) {
			std::cin >> m[i][j];
		}
	}
	for (int i = 80; i >= 1; i--) {
		for (int j = 80; j >= 1; j--) {
			if (i == 80 && j == 80) {
				dp[i][j] = m[i][j];
			} else if (i == 80) {
				dp[i][j] = m[i][j] + dp[i][j+1];
			} else if (j == 80) {
				dp[i][j] = m[i][j] + dp[i+1][j];
			} else {
				dp[i][j] = m[i][j] + std::min(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	std::cout << dp[1][1];
}