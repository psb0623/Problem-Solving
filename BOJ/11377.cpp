#include<bits/stdc++.h>
using namespace std;

vector<int> to[2010];
int d[2010];
bool vis[2010];

bool dfs(int cur){
	for(int next:to[cur]){
		if(vis[next]) continue;
		vis[next] = 1;
		if(d[next]==0||dfs(d[next])){
			d[next] = cur;
			return 1;
		}
	}
	return 0;
}

int n,m,k;
int num[2010];

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			int x;
			scanf("%d",&x);
			to[i].push_back(x);
			to[i+n].push_back(x);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		fill(vis,vis+m+1,0);
		if(dfs(i)){
			ans++;
			num[i]++;
		}
	}
	int cnt = 0;
	for(int i=n+1;i<=2*n;i++){
		fill(vis,vis+m+1,0);
		if(dfs(i)) {
			ans++;
			if(num[i-n]) cnt++;
		}
		if(cnt == k) break;
	}
	printf("%d",ans);
}
