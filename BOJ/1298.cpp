#include<bits/stdc++.h>
using namespace std;
int d[5010];
bool vis[5010];
vector<int> v[110];

bool dfs(int cur){
	for(int next:v[cur]){
		if(vis[next]) continue;
		vis[next] = 1;
		if(d[next]==0 || dfs(d[next])){
			d[next] = cur;
			return 1;
		}
	}
	return 0;
}
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		v[t1].push_back(t2);
	}
	int ans =0 ;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++) vis[i] = 0;
		ans += dfs(i);
	}
	printf("%d",ans);
}
