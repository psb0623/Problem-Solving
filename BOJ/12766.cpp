#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,b,s,m;
vector< pair<int,ll> > v[5010];
vector< pair<int,ll> > rv[5010];
ll d[5010];
ll rd[5010];
ll dp[5010][5010];
ll sum[5010];

void f(int k, int s, int e, int optS, int optE){
	if(s>e) return;
	int mid = (s+e)/2;
	ll mn = 1e18;
	int opt = -1;
	for(int i=optS; i<=min(mid-1,optE); i++) if(mn > dp[k-1][i] + (mid-i-1)*(sum[mid]-sum[i])) {
		mn = dp[k-1][i] + (mid-i-1)*(sum[mid]-sum[i]);
		opt = i;
	}
	dp[k][mid] = mn;
	f(k, s, mid-1, optS, opt);
	f(k, mid+1, e, opt, optE);
}

int main(){
	scanf("%d %d %d %d",&n,&b,&s,&m);
	for(int i=0;i<m;i++){
		int t1,t2;
		ll val;
		scanf("%d %d %lld",&t1,&t2,&val);
		v[t1].push_back({t2,val});
		rv[t2].push_back({t1,val});
	}
	for(int i=1;i<=n;i++) rd[i] = d[i] = 1e18;
	priority_queue< pair<ll,int> > pq;
	pq.push({-0ll,b+1});
	while(!pq.empty()){
		int cur = pq.top().second;
		ll dist = -pq.top().first;
		pq.pop();
		if(dist>d[cur]) continue;
		d[cur] = dist;
		for(auto x:v[cur]){
			int next = x.first;
			ll cost = x.second;
			if(d[cur]+cost<d[next]){
				d[next] = d[cur] + cost; 
				pq.push({-d[next],next});
			}
		}
	}
	pq.push({-0ll,b+1});
	while(!pq.empty()){
		int cur = pq.top().second;
		ll dist = -pq.top().first;
		pq.pop();
		if(dist>rd[cur]) continue;
		rd[cur] = dist;
		for(auto x:rv[cur]){
			int next = x.first;
			ll cost = x.second;
			if(rd[cur]+cost<rd[next]){
				rd[next] = rd[cur] + cost; 
				pq.push({-rd[next],next});
			}
		}
	}
	for(int i=1;i<=b;i++) sum[i] = d[i] + rd[i];
	sort(sum+1,sum+b+1);
	for(int i=1;i<=b;i++) sum[i] += sum[i-1]; 
	for(int i=1;i<=b;i++) dp[1][i] = (i-1)*sum[i];
	for(int i=2;i<=s;i++) f(i,1,b,1,b);
	/*for(int i=1;i<=s;i++){
		for(int j=1;j<=b;j++) printf("%lld ",dp[i][j]);
		puts("");
	}*/
	printf("%lld",dp[s][b]);
}
