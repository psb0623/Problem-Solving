#include<bits/stdc++.h>
using namespace std;
bool used[1001][1001];
bool Y[1001], X[1001];
pair< int, pair<int,int> > p[1000010];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++){
		int t;
		scanf("%d",&t);
		p[m*i+j] = {-t,{i,j}};
	}
	sort(p,p+n*m);
	long long ans = 0ll;
	for(int i=0;i<n*m;i++){
		int y = p[i].second.first;
		int x = p[i].second.second;
		int val = -p[i].first;
		if(Y[y]==1&&X[x]==1) ans += val;
		else Y[y] = X[x] = 1;
	}
	printf("%lld",ans);
}
