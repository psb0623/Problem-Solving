#include<bits/stdc++.h>
using namespace std;
pair<double,int> p[100010];
int W[100010];
double WR[100010];
int n,A;
int main(){
	scanf("%d %d",&n,&A);
	for(int i=0;i<n;i++){
		int x, y, w;
		scanf("%d %d %d",&x,&y,&w);
		p[i] = {sqrt(x*x+y*y), w};
	}
	sort(p,p+n);
	double ans = 0;
	W[0] = p[0].second;
	WR[0] = p[0].first*p[0].second;
	for(int i=0;i<n;i++){
		if(i){
			W[i]= W[i-1] + p[i].second;
			WR[i] = WR[i-1] + p[i].first*p[i].second;
			if(i==n-1) break;
		}
		double ex = W[i]/(2.0*A);
		double rs = p[i].first, re = p[i+1].first;
		if((rs-ex)*(re-ex)<0) ans = max(ans, W[i]*ex - WR[i] - A*ex*ex);
		ans = max(ans, W[i]*rs - WR[i] - A*rs*rs);
		ans = max(ans, W[i]*re - WR[i] - A*re*re);
		/*
		printf("r : %lf, w : %d\n",rs,p[i].second);
		printf("rs : %lf, %lf\n",rs, W[i]*rs - WR[i] - A*rs*rs);
		printf("ex : %lf, %lf\n",rs, W[i]*ex - WR[i] - A*ex*ex);
		printf("re : %lf, %lf\n",re, W[i]*re - WR[i] - A*re*re);
		puts("");*/
	}
	double ex = W[n-1]/(2.0*A);
	if(ex >= p[n-1].first) ans = max(ans, W[n-1]*ex - WR[n-1] - A*ex*ex);
	printf("%lf",ans);
}
