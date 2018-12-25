#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>vc;
ll num,N,K;

int main ()
{
	while(scanf("%lld%lld",&N,&K)==2){
		for (ll i=1;i<=N;i++){
			scanf("%lld",&num);
			vc.push_back(num);
		}

		ll idx = 1,cnt = 0;

		while(cnt<K){

			ll prev = vc[idx-1];
			bool fl = false;

			for (ll i=idx;i<N;i++){
				ll nw = prev | vc[i];

				if (nw!=vc[i] && !fl){
					idx = i;
					fl = true;
				}
				///cout<<i<<" "<<nw<<" "<<idx<<endl;

				prev = vc[i];
				vc[i] = nw;
			}

			if (!fl) break;

			cnt++;
		}

		for (ll i=0;i<N;i++){
			printf("%lld",vc[i]);
			if (i<N-1) printf(" ");
		}

		printf("\n");

		vc.clear();
	}
	return 0;
}

