#include<bits/stdc++.h>
using namespace std;
pair< int, pair<int,int> > p[100010];
pair< int, pair<int,int> > q[100010];
int ans[100010];
int n,m;
int par[100010];
int find(int x){
	if(par[x]<0) return x;
	return par[x] = find(par[x]);
}
void unist(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx!=yy){
		par[xx] = par[xx] + par[yy];
		par[yy] = xx;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) par[i] = -1;
	for(int i=0;i<n-1;i++){
		int t1,t2,val;
		scanf("%d %d %d",&t1,&t2,&val);
		p[i] = {val,{t1,t2}};
	}
	sort(p,p+n-1);
	for(int i=0;i<m;i++){
		int t,val;
		scanf("%d %d",&val,&t);
		q[i] = {val,{t,i}};
	}
	sort(q,q+m);
	int nowq = m-1;
	int nowp = n-2;
	while(nowq>=0){
		while(p[nowp].first>=q[nowq].first){
			unist(p[nowp].second.first,p[nowp].second.second);
			//printf("union %d, %d\n",p[nowp].second.first,p[nowp].second.second);
			nowp--;
		}
		//for(int i=1;i<=n;i++) printf("%d ",par[i]);
		ans[q[nowq].second.second] = -par[find(q[nowq].second.first)];
		//printf("%dth : find %d = %d\n",q[nowq].second.second,q[nowq].second.first,par[find(q[nowq].second.first)]);
		nowq--;
		//puts("");
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]-1);
}
