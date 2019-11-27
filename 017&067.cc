#include <iostream>
#include <algorithm>

int dp[101][101];
 
int main(int argc, char *argv[]) { 
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <= i; j++) {
			std::cin >> dp[i][j];
		}
	} 
	std::cout << dp[14][14] << '\n';
	for (int i = 99; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] += std::max(dp[i+1][j], dp[i+1][j+1]);
		}
	}
	std::cout << dp[0][0];
}