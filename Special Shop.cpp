#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,A,B,xx;

ll cal(ll n){
	ll x = n,y = N-n;
	return A*x*x + B*y*y;
}

ll solve(){
	ll lo = 0,hi = N;
	ll ans = 99999999999999999;

	while(lo<=hi){

		ll mid = (lo+hi)/2;
		ll ans_lo = cal(lo);
		ll ans_hi = cal(hi);
		ll ans_mid = cal(mid);
		if (ans>ans_mid) xx = mid;
		ans = min(ans,ans_mid);
		///cout<<lo<<" "<<mid<<" "<<hi<<endl;
		///cout<<ans_lo<<" "<<ans_mid<<" "<<ans_hi<<endl;

		if (ans_lo<=ans_hi){
			hi = mid - 1;
		}
		else
			lo = mid + 1;

	}
	return ans;
}

void test(){
	ll ans = INT_MAX;
	for (ll i=0;i<=N;i++){
		ll x = i,y = N - i;
		ll sm = A*x*x+B*y*y;
		if (sm<ans) xx = i;
		ans = min(ans,sm);
	}
	///cout<<xx<<" "<<ans<<endl;
}

int main ()
{
	ll cases;

	scanf("%lld",&cases);

	while(cases--){
		scanf("%lld%lld%lld",&N,&A,&B);
		///test();
		printf("%lld\n",(ll)solve());
		///cout<<xx<<endl;
	}
	return 0;
}

