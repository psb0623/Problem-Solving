#include<bits/stdc++.h>

using namespace std;

bool visited[100001];

int n,m;
vector< pair<int,int> > adj[100001];
map< pair<int,int>, bool> mp;
int result[100001];

bool check(int k) {
	queue<int> q;
	int indegree[100001] = {};
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			if(adj[i][j].second<=k) indegree[adj[i][j].first]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) q.push(i);
	}
	
	for(int i=0;i<n;i++){
		if(q.empty()) return false;
		int cur = q.front();
		q.pop();
		for(pair<int,int> next:adj[cur]){
			int j = next.first;
			if(next.second<=k) if(--indegree[j]==0) q.push(j);
		}
	}
	return true;
}

void ans(int k) {
	priority_queue<int> pq;
	int indegree[100001] = {};
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			if(adj[i][j].second<=k) indegree[adj[i][j].first]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) pq.push(-i);
	}
	
	for(int i=0;i<n;i++){
		int cur = -pq.top();
		pq.pop();
		result[i] = cur;
		for(pair<int,int> next:adj[cur]){
			int j = next.first;
			if(next.second<=k) if(--indegree[j]==0) pq.push(-j);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int t, a[100010];
		scanf("%d",&t);
		for(int j=0;j<t;j++) scanf("%d",&a[j]);
		for(int j=0;j<t-1;j++){
			if(mp[{a[j],a[j+1]}]==0){
				adj[a[j]].push_back({a[j+1],i+1});
				mp[{a[j],a[j+1]}] = 1;
			}
		}
	}

	int s=1, e=m;
	while(s<e){
		for(int i=1;i<=n;i++) visited[i] = 0;
		int mid = (s+e)/2;
		if(check(mid)){
			s = mid+1;
		} else e = mid;
	}
	ans(s-1);
	for(int i=0;i<n;i++) printf("%d ",result[i]);
}
