#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int par[100010];
pair<int,int> p[100010];
bool used[100010];
int find(int x){
	if(par[x]<0) return x;
	return par[x] = find(par[x]);
}
void onion(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx==yy) return;
	par[xx] += par[yy];
	par[yy] = xx; 
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) par[i] = -1;
	for(int i=1;i<=m;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		p[i] = {t1,t2};
	}
	for(int i=0;i<k;i++){
		int t;
		scanf("%d",&t);
		used[t] = 1;
	}
	long long ans = 0ll;
	for(int i=1;i<=m;i++) if(!used[i]) onion(p[i].first,p[i].second);
	for(int i=m;i>=1;i--) if(used[i]) {
		int x = find(p[i].first);
		int y = find(p[i].second);
		if(x==y) continue;
		ans += par[x]*par[y];
		onion(x,y);
	}
	printf("%lld",ans);
}
