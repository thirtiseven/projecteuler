#include <iostream>
#define LL long long
using namespace std;
int c1[300],c2[300];

const int maxn = 102;

int num[maxn],dp[maxn];

int main(int argc, char *argv[]) {  
	int n;
		while(cin>>n)
		{
			memset(c1,0,sizeof(c1));
			memset(c2,0,sizeof(c2));
			for(int i=0;i<=n;++i)
			{
				c1[i]=1;
			}
			for(int i=2;i<=n;i++)
			{
				for(int j=0;j<=n;++j)
				{
					for(int k=0;k<=n;k+=i)
					{
						c2[k+j]+=c1[j];
					}
				}
				for(int j=0;j<=n;++j)
				{
					c1[j]=c2[j];
					c2[j]=0;
				}
			}
			cout<<c1[n]<<endl;
		}
		return 0;
}