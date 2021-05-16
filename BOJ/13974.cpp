#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll a[5010], sum[5010];
int opt[5010][5010];
ll d[5010][5010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=n-1;i++)d[i][i+1]=sum[i+1]-sum[i-1],opt[i][i+1]=i;
		for(int l=2;l<n;l++){
			for(int i=1;i+l<=n;i++){
				int j=i+l;
				d[i][j]=1e18;
				for(int k=max(i,opt[i][j-1]);k<=min(j-1,opt[i+1][j]);k++)if(d[i][k]+d[k+1][j]<d[i][j])d[i][j]=d[i][k]+d[k+1][j],opt[i][j]=k;
				d[i][j]+=sum[j]-sum[i-1];
			}
		}
		printf("%lld\n",d[1][n]);
	}
}
