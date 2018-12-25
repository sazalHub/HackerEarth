#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,Q,X,arr[100010],node[100010],parent[100010],u,v,cnt;
vector<ll>graph[100010];

bool DFS(ll from,ll p){
	parent[from] = p;

	ll sum = 0,len = graph[from].size();
	for (ll i=0;i<len;i++){
		ll to = graph[from][i];

		if (p!=to){
			DFS(to,from);
			sum+=node[to];
		}
	}

	node[from] = arr[from] + sum;

	if (node[from]>X) cnt++;
}

void update(ll to,ll val){
	while(to!=0){
		node[to]+=val;
		if (node[to]>X && node[to]-val<=X) cnt++;
		else if (node[to]>X && node[to]-val>X) break;
		to = parent[to];
	}
}

int main ()
{
	///freopen("in.txt","r",stdin);
	while(scanf("%lld%lld%lld",&N,&Q,&X)==3){
		for (ll i=0;i<N-1;i++){
			scanf("%lld%lld",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (ll i=1;i<=N;i++) scanf("%lld",&arr[i]);

		cnt = 0;
		DFS(1,0);

		///for (ll i=1;i<=N;i++) cout<<node[i]<<endl;

		for (ll i=0;i<Q;i++){
			scanf("%lld%lld",&u,&v);
			update(u,v);
			///for (ll j=1;j<=N;j++) cout<<node[j]<<" ";
			///cout<<endl;

			printf("%lld\n",cnt);
		}

		for (ll i=1;i<=N;i++) graph[i].clear();
	}
	return 0;
}
