#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m;
int d[2000];
long long dp[5000];
int num[2000][2000];
int ans[5000];
vector< pair<int,int> > v[2000];
vector<int> p[2000];
long long dfs(int root, int s,int e){
	//printf("(%d,%d), dp[%d] = %d\n",s,e,num[e][s],dp[num[e][s]]);
	if(root==e) return dp[num[e][s]] = 1ll;
	if(dp[num[e][s]]) return dp[num[e][s]];
	long long ans = 1;
	for(int x:p[e]){
		ans += dfs(root,e,x);
		ans %= MOD;
	}
	printf("(%d,%d) : %d\n",s,e,ans);
	
	return dp[num[e][s]] = ans;
}
void dijkstra(int s){
	printf("----%d----\n",s);
	priority_queue< pair<int,int> > pq;
	pq.push({0,s});
	for(int i=1;i<=n;i++) {
		if(i!=s) d[i] = 1e9;
		p[i].clear();
	}
	for(int i=0;i<m;i++) dp[i] = 0;
	while(!pq.empty()){
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		for(auto x:v[cur]){
			int next = x.first;
			int ndist = x.second + dist;
			if(ndist==d[next]) p[next].push_back(cur);
			if(ndist<d[next]){
				p[next].clear();
				d[next] = ndist;
				p[next].push_back(cur);
				pq.push({-ndist,next});
			}
		}
	}
	
	
	vector<int> b[2000];
	for(int i=1;i<=n;i++){
		for(int x:p[i]){
			dfs(s,i,x);
		}
	}
	for(int i=0;i<m;i++) {
		ans[i] += dp[i];
		ans[i] %= MOD;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int t1,t2,val;
		scanf("%d %d %d",&t1,&t2,&val);
		v[t1].push_back({t2,val});
		num[t1][t2] = i;
		//printf("num[%d][%d] = %d\n",t1,t2,i);
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
}
