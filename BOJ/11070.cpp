#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		int s[1010],a[1010];
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) s[i]=a[i]=0;
		for(int i=0;i<m;i++){
			int t1,t2,s1,s2;
			scanf("%d %d %d %d",&t1,&t2,&s1,&s2);
			s[t1] += s1;
			s[t2] += s2;
			a[t1] += s2;
			a[t2] += s1;
		}
		double mx = 0, mn = 1e9;
		for(int i=1;i<=n;i++){
			double res;
			if(s[i]==0&&a[i]==0) res = 0;
			else res = (double)(s[i]*s[i])/(s[i]*s[i]+a[i]*a[i]);
			mn = min(mn,res);
			mx = max(mx,res);
		}
		printf("%d\n%d\n",(int)(mx*1000),(int)(mn*1000));
	}
}
