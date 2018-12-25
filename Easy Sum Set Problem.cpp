#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,M,A[110],C[110];

int main ()
{
	while(scanf("%lld",&N)==1){
		for (ll i=1;i<=N;i++) scanf("%lld",&A[i]);

		scanf("%lld",&M);
		for (ll i=1;i<=M;i++) scanf("%lld",&C[i]);

		sort(A+1,A+N+1);
		sort(C+1,C+M+1);

		map<ll,bool>track;
		vector<ll>vc,v;
		map<ll,ll>cnt;

		for (ll i=1;i<=N;i++){
			for (ll j=1;j<=M;j++){
				ll dif = C[j] - A[i];
				vc.push_back(dif);
			}
		}

		ll len = vc.size();
		for (ll i=1;i<=N;i++){
			///cout<<i<<endl;
			for (ll j=0;j<len;j++){
				ll sm = A[i] + vc[j];
				///cout<<i<<" "<<j<<" "<<sm<<endl;
				if (binary_search(C+1,C+M+1,sm) && !track[vc[j]]){
					cnt[vc[j]]++;
					track[vc[j]] = true;
					///cout<<vc[j]<<" ";
				}
			}
			///cout<<endl;
			track.clear();
		}

		map<ll,ll>::iterator it;

		for (it = cnt.begin();it!=cnt.end();it++){
			///cout<<(*it).first<<" "<<(*it).second<<endl;
			if ((*it).second==N){
				v.push_back((*it).first);
			}
		}

		len = v.size();

		for (ll i=0;i<len;i++){
			printf("%lld",v[i]);
			if (i<len-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}

