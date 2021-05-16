#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
int n,m,k;
long long d[5010];
long long res[5010];
long long a[5010];
long long c[5010];
long long num[26];
long long P(long long a, long long n){
	//if(a==0&&n==0) return 0;
	if(n==0) return 1ll;
	if(n==1) return a;
	long long tmp = P(a,n/2);
	if(n%2) return (((tmp*tmp)%M)*a)%M;
	else return (tmp*tmp)%M;
}
int main(){
	d[0] = 1ll;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i],&c[i]);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=i) {
				d[i] += d[i-a[j]];
				d[i] %= M;
				if(i==k) {
					res[c[j]] += d[i-a[j]];
					res[c[j]] %= M;
				}
			}
		}
	}
	for(int i=0;i<m;i++) {
		char t;
		scanf("\n%c",&t);
		num[t-'A']++;
	}
	long long ans = 1ll;
	for(int i=0;i<26;i++){
		if(num[i]==0) continue;
		long long tmp = 0ll;
		for(int j=1;j<=n;j++){
			//printf("%lld^%lld = %lld\n",res[j],num[i],P(res[j],num[i]));
			tmp += P(res[j],num[i]);
			tmp %= M;
		}
		ans *= tmp;
		ans %= M;
	}
	printf("%lld",ans);
}
