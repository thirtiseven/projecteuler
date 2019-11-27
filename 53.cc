#include <iostream>

using ll = long long;
const int maxn = 101;

ll c[maxn][maxn], x[maxn][maxn];
ll ans = 0;

void gaoC() {
	int i,j;
	for (i = 0; i < maxn; i++) {
		c[i][0] = c[i][i] = 1;
	}
	for (i = 1; i < maxn; i++) {
		std::cout << i << ": ";
		for(j = 1; j <= i; j++) {
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if (c[i][j] >= 1000000) {
				x[i][j] = 1;
			} else {
				x[i][j] = 0;
			}
//			c[i][j] %= mod;
		}
		for (j = 2; j <= i/2; j++) {
			if (x[i][j-1] == 1) {
				x[i][j] = 1;
			}
		}
		for (j = i; j >= i/2; j--) {
			if (x[i][j+1] == 1) {
				x[i][j] = 1;
			}
		}
		for (j = 1; j <= i; j++) {
			std::cout << x[i][j];
			if (x[i][j] == 1) {
				ans++;
			}
		}
		std::cout << '\n';
	}
}

int main(int argc, char *argv[]) {  
	gaoC();
	std::cout << ans << '\n';
}