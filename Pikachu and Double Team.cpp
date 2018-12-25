#include<bits/stdc++.h>
#define ll long long
using namespace std;

double A,B,R,x,y,r;
double PI = 3.14159265358979323846;
ll N;

struct type{
	double x,y,r;
	type(ll a,ll b,ll c){
		x = a;
		y = b;
		r = c;
	}
};
vector<type>circles;

bool inside(double x,double y,double xx,double yy,double r){
	x = x-xx;
	y = y-yy;

	return (x*x+y*y<=r*r);
}

int main ()
{
	///cout<<PI<<endl;
	while(scanf("%lld%lf%lf%lf",&N,&A,&B,&R)==4){

		///cout<<N<<" "<<A<<" "<<B<<" "<<R<<endl;

		for (ll i=0;i<N;i++){
			scanf("%lf%lf%lf",&x,&y,&r);
			circles.push_back(type(x,y,r));
		}

		double in = 0,total = 0;
		for (double xx=-R+0.03;xx<R;xx+=0.03){
			for (double yy=-R+0.03;yy<R;yy+=0.03){
				if (!inside(xx,yy,A,B,R)) continue;

				for (ll i=0;i<N;i++){
					if (inside(xx,yy,circles[i].x,circles[i].y,circles[i].r)){
						in++;
						break;
					}
				}
				total++;
			}
		}
		///cout<<(in/total)*(PI*R*R)<<endl;

		printf("%.10lf\n",(in/total)*(PI*R*R));

		circles.clear();
	}
	return 0;
}

