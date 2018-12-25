#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll pwr[1001000],fact[1000500];

ll power(ll base,ll pr)
{
    ll ret,y;
    if (pr==0) return 1;
    if (pr%2==0)
    {
        y=power(base,pr/2);
        ret=(y*y)%mod;
    }
    else
    {
        y=power(base,pr/2);
        ret=((y*y)%mod*base%mod)%mod;
    }
    return ret;
}

int main ()
{
	ll N,M;
	pwr[0] = 1;
	for (ll i=1;i<=1000050;i++) pwr[i] = (pwr[i-1]*2)%mod;
	fact[0] = 1;
	for (ll i=1;i<=1000050;i++) fact[i] = (fact[i-1]*i)%mod;

	while(scanf("%lld%lld",&N,&M)==2){
		ll ans = 0;
		for (ll i=0;i<=N;i++){
			ll tmp = (power(fact[i],mod-2) * power(fact[N-i],mod-2))%mod;
			tmp = (tmp * fact[N])%mod;
			tmp = (tmp * power(pwr[N-i]-1,M))%mod;
			if (i%2) tmp = tmp * -1;
			///cout<<i<<" "<<tmp<<endl;
			ans = (ans + tmp)%mod;
			if  (ans<0) ans = ans + mod;
		}

		printf("%lld\n",ans);
	}
	return 0;
}

