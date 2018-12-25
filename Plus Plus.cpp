#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,M,arr[55][55];
bool track[55][55];

bool check(ll r1,ll c1,ll r2,ll c2){

	track[55][55] = false;

	track[r1][c1] = true;
	track[r1-1][c1] = true;
	track[r1+1][c1] = true;
	track[r1][c1-1] = true;
	track[r1][c1+1] = true;

	if (track[r2][c2]) return false;
	if (track[r2-1][c2]) return false;
	if (track[r2+1][c2]) return false;
	if (track[r2][c2-1]) return false;
	if (track[r2][c2+1]) return false;


	return true;
}

int main ()
{
	while(scanf("%lld%lld",&N,&M)==2){
		for (ll i=1;i<=N;i++){
			for (ll j=1;j<=M;j++){
				scanf("%lld",&arr[i][j]);
			}
		}

		ll ans = 0;

		for (ll i=2;i<N;i++){
			for (ll j=2;j<M;j++){

				for (ll k=2;k<N;k++){
					for (ll l=2;l<M;l++){

						bool fl = check(i,j,k,l);

						if (fl){
							ll tmp = arr[i][j]*arr[k][l] + arr[i-1][j]*arr[k-1][l]+
									 arr[i+1][j]*arr[k+1][l] + arr[i][j-1]*arr[k][l-1]+
									 arr[i][j+1]*arr[k][l+1];
							ans = max(ans,tmp);
							///cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<tmp<<endl;
						}
					}
				}

			}
		}

		printf("%lld\n",ans);
	}
	return 0;
}

