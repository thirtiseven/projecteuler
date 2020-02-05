#include <iostream>

const int max=1000001;

using ll = long long;
ll minDiv[max],phi[max],sum[max];
void genPhi()
{
	for(ll i=1;i<max;i++)
	{
		minDiv[i]=i;
	}
	for(ll i=2;i*i<max;i++)
	{
		if(minDiv[i]==i)
		{
			for(ll j=i*i;j<max;j+=i)
			{
				minDiv[j]=i;
			}
		}
	}
	phi[1]=1;
	for(ll i=2;i<max;++i)
	{
		phi[i]=phi[i/minDiv[i]];
		if((i/minDiv[i])%minDiv[i]==0)
		{
			phi[i]*=minDiv[i];
		}
		else
		{
			phi[i]*=minDiv[i]-1;
		}
	}
}

int main(int argc, char *argv[]) {  
	genPhi();
	ll up = 1, down = 0;
	ll ans = 0;
	for (ll i = 2; i < max; i++) {
		if (phi[i]*down < up*i) {
			up = phi[i];
			down = i;
			ans = i;
		}
	}
	std::cout << ans << '\n';
}