#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>graph[500050],eular;
ll V,E,Q,K;
bool visited[500050];
ll dist[500050],ans[200050],first[500050];
ll tree[4000400];

void DFS(ll u,ll dis){
	///cout<<u<<endl;
	visited[u] = true;
	dist[u] = dis;
	first[u] = eular.size();
	eular.push_back(u);

	for (ll i=0;i<graph[u].size();i++){
		ll v = graph[u][i];
		///cout<<v<<endl;
		if (!visited[v]){
			DFS(v,dis+1);
			eular.push_back(u);
		}
	}
}

void build(ll node,ll l,ll r){
	if (l==r){
		tree[node] = eular[l];
		return;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	build(lft,l,mid);
	build(rgt,mid+1,r);

	ll lf = tree[lft],rg = tree[rgt];
	///cout<<node<<" = "<<lf<<" "<<rg<<endl;

	if (first[lf]<first[rg]) tree[node] = lf;
	else tree[node] = rg;
}

ll query(ll node,ll l,ll r,ll to,ll from){
	if (l>from || r<to) return -1;
	if (to<=l && r<=from) return tree[node];

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	ll ret1 = query(lft,l,mid,to,from);
	ll ret2 = query(rgt,mid+1,r,to,from);

	if (ret1==-1) return ret2;
	if (ret2==-1) return ret1;

	if (first[ret1]<first[ret2]) return ret1;
	else return ret2;
}

ll LCA(ll u,ll v){
	if (first[v]<first[u]) swap(u,v);

	return query(1,0,eular.size()-1,first[u],first[v]);
}

int main ()
{
	///freopen("in.txt","r",stdin);
	while(scanf("%lld%lld",&V,&Q)==2){

		ll u,v;
		for (ll i=0;i<V-1;i++){
			scanf("%lld%lld",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);

			visited[i+1] = false;
		}

		DFS(1,0);
		build(1,0,eular.size()-1);

		for (ll q=1;q<=Q;q++){
			scanf("%lld",&K);

			vector<ll>ss;
			ll dst = -1,node = 0;
			for (ll i=0;i<K;i++){
				scanf("%lld",&u);
				ss.push_back(u);

				if (dst<dist[u]){
					dst = dist[u];
					node = u;
				}
			}

			ans[q] = -1;
			///cout<<q<<" = "<<endl;
			for (ll i=0;i<K;i++){
				///cout<<node<<" "<<ss[i]<<" -> "<<LCA(node,ss[i])<<endl;
				ll d = dist[node] + dist[ss[i]] - 2*dist[LCA(node,ss[i])];
				///cout<<d<<endl;
				ans[q] = max(ans[q],d);
			}
			///cout<<ans[q]<<endl;
		}

		for (ll i=1;i<=Q;i++) printf("%lld\n",ans[i]);

		for (ll i=0;i<=V;i++) graph[i].clear();
		eular.clear();

	}
	return 0;
}

