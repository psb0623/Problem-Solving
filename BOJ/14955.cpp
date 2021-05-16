#include <bits/stdc++.h>
using namespace std;

int n,m;
 
struct EDGE {
    int a, b, c;
} edge[510];
 
int E;
int to[1010],flow[1010],dist[110],cnt[110];
vector<int> v[110];

void add_edge(int t1, int t2){
	
    v[t1].push_back(E);
	to[E] = t2;
	flow[E] = 1;
	E++;
	
    v[t2].push_back(E);
	to[E] = t1;
	flow[E] = 1;
	E++;
}
 
void bfs(int b){
    for(int i=1;i<=n;i++) dist[i] = n;
	for(int i=0;i<=n;i++) cnt[i] = 0;
    queue<int> q;
    dist[b] = 0;
	q.push(b);
    while(!q.empty()){
        int cur = q.front();
		q.pop();
        for(int x:v[cur]){
            int t = to[x], f = flow[x^1];
            if(f && dist[t]>dist[cur]+1){
                dist[t] = dist[cur]+1;
				q.push(t);
            }
        }
    }
    for(int i=1;i<=n;i++) cnt[dist[i]]++;
}
 
vector<int> path;

int dfs(int cur, int dest){
    if(cur==dest) return 1;
    for(int x:v[cur]){
        int t = to[x], f = flow[x];
        if(!f||dist[t]+1!=dist[cur]) continue;
        path.push_back(x);
        int k = dfs(t,dest);
        if (k) return k;
        path.pop_back();
    }
    int tmp = dist[cur];
	dist[cur] = n;
    for(int x:v[cur]){
        int t = to[x], f = flow[x];
        if(f&&dist[cur]>dist[t]+1) dist[cur] = dist[t]+1;
    }
    cnt[dist[cur]]++;
    if(!--cnt[tmp]) return -1;
    return 0;
}
 
int mincut(int a, int b, int c){
    int res = 0;
    E = 0;
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1;edge[i].c<c;i++) add_edge(edge[i].a,edge[i].b);
    bfs(b);
    while(dist[a]<n){
        path.clear();
        int k = dfs(a,b);
        if(k<0) break;
        if(!k) continue;
        for(int x:path){
        	flow[x]--;
			flow[x^1]++;
		}
        res++;
    }
    return res;
}
 
int main(){
    scanf("%d %d", &n, &m);
    for (int i=1;i<=m;i++){
        int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
        edge[i] = {a, b, c};
    }
    sort(edge+1, edge+m+1, [](const EDGE &a, const EDGE &b){
        return a.c<b.c;
    });
    int ans = 0;
    for(int i=1;i<=m;i++) ans += mincut(edge[i].a, edge[i].b, edge[i].c);
    printf("%d", ans);
}
