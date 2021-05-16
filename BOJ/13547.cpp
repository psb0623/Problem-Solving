#include<bits/stdc++.h>
using namespace std;
int n,m,s,e;
int a[100010], st[100010], ans[100010], prv[1000010];
vector< pair<int,int> > Q[100010];
int get(int x){
	int ret = 0;
	while(x > 0){
		ret += st[x];
		x -= (x & -x);
	}
	return ret;
}
void update(int x, int v){
	while(x <= n){
		st[x] += v;
		x += (x & -x);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cin >> m;
	for(int i=0;i<m;i++) {
		cin >> s >> e;
		Q[e].push_back({s,i});
	}
	for(int i=1;i<=n;i++){
		update(prv[a[i]]+1, 1); update(i+1, -1);
		for(pair<int,int> x:Q[i]) ans[x.second] = get(x.first);
		prv[a[i]] = i;
	}
	for(int i=0;i<m;i++) cout << ans[i] << "\n";
}
