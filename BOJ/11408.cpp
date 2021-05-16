#include<bits/stdc++.h>
using namespace std;
int C[1000][1000], F[1000][1000];

vector< pair<int,int> > v[1000];

int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			int next, cost;
			scanf("%d %d",&next,&cost);
			v[i].push_back({n+next,cost});
			v[n+next].push_back({i,-cost});
			C[i][n+next] = 1;

		}
	}
	// source : 0
	for(int i=1;i<=n;i++){
		v[0].push_back({i,0});
		v[i].push_back({0,0});
		C[0][i] = 1;
	}
	// sink : n+m+1
	for(int i=n+1;i<=n+m;i++){
		v[i].push_back({n+m+1,0});
		v[n+m+1].push_back({i,0});
		C[i][n+m+1] = 1;
	}
	
	int cnt = 0;
	int ans = 0;
	
	while(1){
		int prev[1000];
		int d[1000];
		bool inq[1000];
		
		for(int i=0;i<=n+m+1;i++){
			inq[i] = 0;
			prev[i] = -1;
			d[i] = 1e9;
		}
		
		queue<int> q;
		d[0] = 0;
		q.push(0);
		inq[0] = 1;
		
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			inq[cur] = 0;

			for(auto x:v[cur]){
				int next = x.first;
				int cost = x.second;
				if(C[cur][next] - F[cur][next] <= 0) continue;
				
				if(d[next] > d[cur] + cost){
					prev[next] = cur;
					d[next] = d[cur] + cost;
					if(!inq[next]){
						q.push(next);
						inq[next] = 1;
					}
				}
			}
		}
		
		if(prev[n+m+1] == -1) break;
		
		int flow = 1e9;
		
		for(int i=n+m+1;i;i=prev[i]) flow = min(flow, C[prev[i]][i]-F[prev[i]][i]);
		for(int i=n+m+1;i;i=prev[i]){
			F[prev[i]][i] += flow;
			F[i][prev[i]] -= flow;
		}
		//printf("%d %d\n",d[n+m+1],flow);
		cnt += flow;
		ans += d[n+m+1] * flow;
	}
	
	printf("%d\n%d",cnt,ans);
}
