#include <iostream>
#include <algorithm>

#include <vector> 
#include <algorithm> 

const int maxn = 100;
const int maxm = 10000;

class Kruskal { 
	struct UdEdge {
		int u, v, w;
		UdEdge(){}
		UdEdge(int u,int v,int w):u(u), v(v), w(w){}
	};
	int N, M;
	UdEdge pool[maxm]; 
	UdEdge *E[maxm]; 
	int P[maxn];
	int Find(int x){ 
		if(P[x] == x)
			return x;
		return P[x] = Find(P[x]);
	}
public:
	static bool cmp(const UdEdge *a, const UdEdge *b) {
		return a->w < b->w; 
	}
	void Clear(int n) { 
		N = n;
		M = 0; 
	}
	void AddEdge(int u, int v, int w) {
		pool[M] = UdEdge(u, v, w);
		E[M] = &pool[M];
		++M; 
	}
	int Run() {
		int i, ans=0;
		for(i = 1; i <= N; ++i) 
			P[i] = i;
		std::sort(E, E+M, cmp); 
		for(i = 0; i < M; ++i) {
			UdEdge *e = E[i]; 
			int x = Find(e->u); 
			int y = Find(e->v); 
			if(x != y) {
				P[y] = x;
				ans += e->w; 
			}
		}
		return ans; 
	}
}gao;

int temp_edge[45][45];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	gao.Clear(40);
	int x;
	int sum = 0;
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			std::cin >> temp_edge[i][j];
		}
	}
	for (int i = 0; i < 39; i++) {
		for (int j = i+1; j < 40; j++) {
			if (temp_edge[i][j] != -1) {
				sum += temp_edge[i][j];
				gao.AddEdge(i+1, j+1, temp_edge[i][j]);
			}
		}
	}
	std::cout << sum - gao.Run();
}