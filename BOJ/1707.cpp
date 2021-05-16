#include<bits/stdc++.h>
using namespace std;
int visited[20010];
bool color[20010];
vector<int> adj[20010];
bool dfs(int cur, bool c){
	if(visited[cur]) {
		if(c == color[cur]) return 1;
		return 0;
	}
	visited[cur] = 1;
	color[cur] = c;
	bool res = 1;
	for(int next:adj[cur]){
		res &= dfs(next, !c);
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			adj[i].clear();
			visited[i] = 0;
		}
		for(int i=0;i<m;i++){
			int t1,t2;
			scanf("%d %d",&t1,&t2);
			adj[t1].push_back(t2);
			adj[t2].push_back(t1);
		}
		bool res = 1;
		for(int i=1;i<=n;i++) if(!visited[i]) res &= dfs(i,0);
		printf("%s\n", res?"YES":"NO");
	}
}
