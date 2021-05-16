#include<bits/stdc++.h>
using namespace std;
long long d[801][8001];
long long a[8001],sum[8001];

void f(int k, int s, int e, int optS, int optE){
	if(s>e) return;
	long long mn = 1e18;
	int opt = -1;
	int i = (s+e)/2;
	//printf("%d %d %d\n",i,k,optE);
	for(int j=optS; j<=optE; j++){
		if(j>=i) break;
		long long tmp = d[k-1][j] + (i-j)*(sum[i]-sum[j]);
		if(tmp < mn) {
			mn = tmp;
			opt = j;
		}
	}
	d[k][i] = mn;
	f(k, s, i-1, optS, opt);
	f(k, i+1, e, opt, optE);
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) d[1][i] = i*sum[i];
	for(int i=2;i<=k;i++) f(i,i,n,i-1,n);
	/*for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) printf("%lld ",d[i][j]);
		puts("");
	}*/
	printf("%lld",d[min(n,k)][n]);
}
