#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[600050],tmp;

struct data{
	ll val,marked;
};
data tree[2400500];

void build(ll node,ll l,ll r){
	///cout<<l<<" "<<r<<" "<<tree[node].marked<<endl;
	if (l==r){
		///if (arr[l]>0) cout<<l<<" "<<arr[l]<<endl;
		tree[node].val = arr[l];
		tree[node].marked = 1;
		if (arr[l]==0) tree[node].marked = 0;
		return;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	build(lft,l,mid);
	build(rgt,mid+1,r);

	tree[node].val = max(tree[lft].val,tree[rgt].val);
	tree[node].marked = tree[lft].marked + tree[rgt].marked;
}

ll getIndx(ll node,ll l,ll r,ll idx){
	///cout<<l<<" "<<r<<" "<<tree[node].marked<<endl;
	if (l==r){
		tmp = tree[node].val;
		return l;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	if (idx<=tree[lft].marked) return getIndx(lft,l,mid,idx);
	else return getIndx(rgt,mid+1,r,idx-tree[lft].marked);
}

ll query(ll node,ll l,ll r,ll from,ll to){

	if (l>to || r<from) return 0;

	if (from<=l && r<=to) return tree[node].val;

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	return max(query(lft,l,mid,from,to),query(rgt,mid+1,r,from,to));
}

void update(ll node,ll l,ll r,ll idx,ll val,ll mark){
	///cout<<l<<" "<<r<<endl;
	if (l==r){
		///cout<<l<<" "<<val<<endl;
		tree[node].val = val;
		tree[node].marked = mark;
		return;
	}

	ll mid = (l+r)/2;
	ll lft = node*2;
	ll rgt = node*2 + 1;

	if (idx<=mid) update(lft,l,mid,idx,val,mark);
	else update(rgt,mid+1,r,idx,val,mark);

	tree[node].val = max(tree[lft].val,tree[rgt].val);
	tree[node].marked = tree[lft].marked + tree[rgt].marked;
}

int main ()
{
	ll l,r,N,Q,k,p,type;
	///freopen("in.txt","r",stdin);
	while(scanf("%lld%lld",&N,&Q)==2){

		memset(arr,0,sizeof(arr));
		for (ll i=1;i<=N;i++){
			scanf("%lld",&arr[Q+i]);
		}
		///for (ll i=1;i<=N;i++) cout<<arr[Q+i]<<endl;

		memset(tree,0,sizeof(tree));

		ll st = Q+1;
		ll en = Q+N;

		N = Q + N + Q;
		///cout<<N<<endl;
		build(1,1,N);

		for (ll i=0;i<Q;i++){
			scanf("%lld",&type);

			if (type==1){
				scanf("%lld%lld",&l,&r);
				///cout<<l<<" "<<r<<endl;
				l = getIndx(1,1,N,l);
				r = getIndx(1,1,N,r);

				///cout<<l<<" "<<r<<endl;
				printf("%lld\n",query(1,1,N,l,r));
			}
			else if (type==2){
				scanf("%lld%lld",&p,&k);
				///cout<<k<<endl;
				k = getIndx(1,1,N,k);
				//cout<<tmp<<endl;

				///cout<<k<<" "<<tree[k].val<<endl;
				if (p==1){
					en++;
					update(1,1,N,en,tmp,1);
					update(1,1,N,k,0,0);
				}
				else{
					st--;
					///cout<<st<<endl;
					update(1,1,N,st,tmp,1);
					update(1,1,N,k,0,0);
				}
			}
		}
	}
	return 0;
}

