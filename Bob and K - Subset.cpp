#include<bits/stdc++.h>
#define ll int
using namespace std;
ll N,K,num;
vector<ll>arr;
bool visited[2150];

struct data{
	ll idx,OR;
	data(ll id,ll val){
		idx = id,OR = val;
	}
};
vector<data>V,vc;

int main ()
{
	while(scanf("%d%d",&N,&K)==2){
		for (ll i=0;i<2100;i++) visited[i] = false;
		V.clear();
		vc.clear();
		arr.clear();

		for (ll i=1;i<=N;i++){
			scanf("%d",&num);
			if (!visited[num]){
				visited[num] = true;
				arr.push_back(num);
			}
		}

		N = arr.size();

		for (ll i=0;i<N;i++) V.push_back(data(i,arr[i]));

		ll cnt = N;
		if (K>N) K = N;
		///cout<<N<<" "<<K<<endl;
		ll k = 2;
		bool flag = true;

		while(k<=K && flag){
			bool fl = false;

			for (ll i=0;i<V.size() && flag;i++){
				for (ll j=V[i].idx+1;j<N && flag;j++){
					ll bitwise_or = V[i].OR | arr[j];

					if (!visited[bitwise_or]){
						vc.push_back(data(j,bitwise_or));
						visited[bitwise_or] = true;
						cnt++;
					}
					else if (!fl){
						vc.push_back(data(j,bitwise_or));
						fl = true;
					}

					if (cnt>=2047) flag = false;
				}
			}

			V = vc;
			vc.clear();
			k++;
		}

		printf("%d\n",cnt);

	}
	return 0;
}

