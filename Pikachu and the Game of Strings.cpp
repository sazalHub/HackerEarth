#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
	ll N,days;
	string s,t;

	while(scanf("%lld",&N)==1){
		cin>>s;
		cin>>t;

		days = 0;

		for (ll i=0;s[i];i++){
			ll dif = ((ll)t[i]-(ll)s[i]);

			if (dif<0) dif = dif + 26;

			///cout<<dif<<endl;

			days+=(ll)(dif/13) + (ll)(dif%13);
		}

		cout<<days<<endl;
	}
	return 0;
}

