#include<bits/stdc++.h>
using namespace std;
vector<int> v[100010];
vector<int> tree[100010];
bool visited[100010];
int depth[100010];
int dist[100010];
int n,k;
void build(int n, int d){
	visited[n] = 1;
	depth[n] = d;
	for(int x:v[n]) if(!visited[x]) {
		tree[n].push_back(x);
		build(x,d+1);
	}
}
int dfs(int n){
	if(tree[n].size()==0) {
		dist[n] = 0;
		return depth[n];
	}
	int mind = 1e9;
	for(int x:tree[n]) mind = min(mind,dfs(x));
	if(mind!=1e9) dist[n] = mind - depth[n];
	return mind;
}
int f(int n){
	if(depth[n]>=dist[n]) return 1;
	int ans = 0;
	for(int x:tree[n]) ans += f(x);
	return ans;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n-1;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	build(k,0);
	dfs(k);
	/*for(int i=1;i<=n;i++,puts("")) {
		printf("%d : depth=%d, dist=%d, jason=",i,depth[i],dist[i]);
		for(int x:tree[i]) printf("%d ",x); 
	}*/
	printf("%d",f(k));
}
