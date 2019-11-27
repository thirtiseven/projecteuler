#include <iostream>

int main(int argc, char *argv[]) {  
	int alice[400000];
	alice[0] = 1, alice[1] = 2;
	int ans = 2, cnt = 2;
	while(1) {
		alice[cnt] = alice[cnt-1] + alice[cnt-2];
		if(alice[cnt] >= 4000000) {
			break;
		}
		if(alice[cnt] % 2 == 0) {
			std::cout << alice[cnt] << " ";
			ans += alice[cnt];
		}
		cnt++;
	}
	std::cout << ans;
	return 0;
}