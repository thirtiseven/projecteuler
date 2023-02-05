#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <algorithm>
#include <iterator>
#define int long long int
#define ld long double
#define ios ios::sync_with_stdio(0),cin.tie(0)
#define N 2000007
#define INF 1000000000LL
#define swift 1000000000
using namespace std;
int n;
ld r,d,ans;
int dx[25] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
int dy[25] = {-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
unordered_map<int, int> m;

void solve();
inline void init();
void solve();
bool insert(int,int,int);
inline double dis(int,int);
inline int Grid(int);

struct node{
    int x,y,ind;
}point[N];

//函式實作
inline void init(){
    m.clear();
    cout<<fixed<<setprecision(6);
}

inline int Grid(int ind){ //input網格座標
    int x = point[ind].x/r;
    int y = point[ind].y/r;
    return x*INF+y;
}

inline ld dis(node a,node b){
    ld x = a.x-b.x,y = a.y-b.y;
    return sqrt(x*x+y*y);
}

void solve(){
    m.insert(make_pair(Grid(0),0));m.insert(make_pair(Grid(1),1));
    for(int ind = 2;ind < n;ind++){
        int x = point[ind].x/r,y = point[ind].y/r,better=0;
        for(int i=0;i<25;i++){
            int nx = x+dx[i],ny = y+dy[i];
            auto it = m.find(nx*INF+ny);
            if(it!=m.end()){
                double distance = dis(point[it->second],point[ind]);
                if(distance<d){
                    better = 1;
                    ans = dis(point[it->second],point[ind]);
                    d = distance;
                    r = d/2;
                }
            }
        }
        if(better){
            m.clear();
            for(int i=0;i<=ind;i++)m.insert(make_pair(Grid(i),i));
        }
        else{
            m.insert(make_pair(Grid(ind), ind));
        }
    }
}

using ll = long long;

const int maxn = 4e6+7;

ll cur = 290797;
const ll mod = 50515093;

signed main(){
    ios;
    n = 2000000;
    init();
    for(int i=0;i<n;i++){
        int x,y;
        x = cur;
        cur = (cur * cur) % mod;
        y = cur;
        cur = (cur * cur) % mod;
        x+=swift;y+=swift;
        point[i].x = x;point[i].y = y;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(point, point+n,g);
    int smalln = sqrt(n);
    ans = dis(point[0],point[1]);
    d = dis(point[0], point[1]);
    for(int i=0;i<=smalln;i++){
        for(int j=i+1;j<=smalln;j++){
            d = min(d,dis(point[i], point[j]));
            ans = min(ans,dis(point[i],point[j]));
        }
    }
    r = d/2;
    solve();
    cout<<setprecision(10)<<fixed<< ans<<endl;
}