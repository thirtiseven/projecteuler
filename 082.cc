#include <iostream>
#include <algorithm>

const int maxn = 82;
const int inf = INT_MAX;

int n = 80;
int m[maxn][maxn];
int dp[maxn][maxn];

int gao(int a, int b, int c) {
	int res = 0;
	if (b > c) {
		std::swap(b, c);
	}
	for (int i = b; i <= c; i++) {
		res += m[i][a];
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> m[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][0] = m[i][0];
	}
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n; i++) {
			dp[i][j] = inf;
			for (int k = 0; k < n; k++) {
				dp[i][j] = std::min(dp[i][j], dp[k][j-1] + gao(j, i, k));
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < n; i++) {
		ans = std::min(ans, dp[i][n-1]);
	}
	std::cout << ans << '\n';
}