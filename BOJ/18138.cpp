#include<bits/stdc++.h>
using namespace std;
int d[210];
bool vis[210];
vector<int> v[210];

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
int a[210], b[210];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=m;i++) scanf("%d", &b[i]);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] <= 2*b[j] && 4*b[j] <= 3*a[i]) v[i].push_back(j);  // a[i]/2 <= b[j] <= a[i]*3/4
			else if(a[i] <= b[j] && 4*b[j] <= 5*a[i]) v[i].push_back(j);  // a[i] <= b[j] <= a[i]*5/4
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++) vis[i] = 0;
		ans += dfs(i);
	}
	printf("%d",ans);
}
