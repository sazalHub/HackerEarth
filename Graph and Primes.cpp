#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>primes,weight;
ll V,E,u,v,cost,len,parent[100005],dist[100005];
bool visited[5055],visit[5000050];

struct NODE{
    ll node,cost;
}to,from;
vector<NODE>graph[5005];

struct edge{
	ll u,v,w;
}edges[200010];

map<ll, map<ll,ll> >wt;

bool operator<(NODE a,NODE b)
{
    return (a.cost>b.cost);
}

void prime_generator(){
	visit[1] = true;
	for (ll i=4;i<=5000000;i+=2) visit[i] = true;
	primes.push_back(2);

	for (ll i=3;i<=5000000;i+=2){
		if (!visit[i]){
			primes.push_back(i);
			///if (i<=100) cout<<i<<endl;
			for (ll j=i*i;j<=5000000;j+=2*i) visit[j] = true;
		}
	}
	///cout<<primes.size()<<endl;
}

bool check(ll val){
	if (val<=5000000) return visit[val];

	for (ll i=0;primes[i]*primes[i]<=val;i++){
		if (val%primes[i]==0) return true;
	}
	return false;
}

void DIJKSTRA()
{
    for (ll i=1;i<=V;i++)dist[i] = INT_MAX,parent[i] = -1;

    priority_queue<NODE>Q;
    to.node = 1;
    to.cost = 0;
    dist[1] = 0;
    parent[1] = 0;
    Q.push(to);

    while(!Q.empty())
    {
        from = Q.top();
        Q.pop();
        ///cout<<from.node<<" = "<<endl;

        len = graph[from.node].size();
        for (ll i=0;i<len;i++){
			to = graph[from.node][i];

			if (to.node==parent[from.node]) continue;

			ll w = -1;
			for (ll j=0;j<weight.size();j++){
				if (!check(dist[from.node]+weight[j])){
					w = j;
					break;
				}
			}

			if (w==-1){
				if (wt[from.node][to.node]==-1){
					wt[from.node][to.node] = wt[to.node][from.node] =  weight[0];
					to.cost = weight[0];
					weight.erase(weight.begin()+0);
				}
			}
			else{
				if (dist[from.node]+weight[w]<dist[to.node]){
					if (wt[from.node][to.node]==-1){
						wt[from.node][to.node] = wt[to.node][from.node] =  weight[w];
						to.cost = weight[w];
						weight.erase(weight.begin()+w);
					}
				}
				else{
					if (wt[from.node][to.node]==-1){
						wt[from.node][to.node] = wt[to.node][from.node] =  weight[weight.size()-1];
						to.cost = weight[weight.size()-1];
						weight.erase(weight.begin()+weight.size()-1);
					}
				}
			}

			///cout<<to.node<<" "<<to.cost<<endl;

			if (dist[from.node]+to.cost<dist[to.node]){
				dist[to.node] = dist[from.node]+to.cost;
                to.cost = dist[to.node];
                parent[to.node] = from.node;
				Q.push(to);
			}
        }
    }
}

int main ()
{
	prime_generator();

	///freopen("in.txt","r",stdin);
	while(scanf("%lld%lld",&V,&E)==2){

		wt.clear();
		for (ll i=1;i<=E;i++){
			scanf("%lld%lld",&u,&v);
			to.node = v;
			to.cost = INT_MAX;
			graph[u].push_back(to);
			to.node = u;
			graph[v].push_back(to);
			edges[i].u = u;
			edges[i].v = v;
			wt[u][v] = wt[v][u] = -1;
		}

		for (ll i=0;i<E;i++){
			scanf("%lld",&cost);
			weight.push_back(cost);
		}
		sort(weight.begin(),weight.end());

		DIJKSTRA();

		for (ll i=1;i<=E;i++){
			u = edges[i].u,v = edges[i].v;
			printf("%lld\n",wt[u][v]);
		}

		for (ll i=0;i<=V;i++) graph[i].clear();

	}
	return 0;
}

