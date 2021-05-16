#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;
int n,m,s,e;
long long d[100010];
long long ans[100010];
vector< pair<int,long long> > v[100010];
int main(){
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=0;i<m;i++){
		int t1,t2;
		long long val;
		scanf("%d %d %lld",&t1,&t2,&val);
		v[t1].push_back({t2,val});
		v[t2].push_back({t1,val});
	}
	priority_queue< pair<long long, int> > pq;
	for(int i=1;i<=n;i++) d[i] = 1e18;
	ans[s] = 1ll;
	d[s] = 0ll;
	pq.push({0ll,s});
	while(!pq.empty()){
		long long dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(dist>d[cur]) continue;
		for(auto x:v[cur]){
			int next = x.first;
			long long ndist = dist + x.second;
			if(ndist<d[next]){
				d[next] = ndist;
				ans[next] = ans[cur];
				pq.push({-ndist,next});
			} else if(ndist==d[next]) {
				ans[next] += ans[cur];
				ans[next] %= MOD;
			}
		}
	}
	printf("%lld",ans[e]);
}
