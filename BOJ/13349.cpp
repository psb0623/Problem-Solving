#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010][1010];
bool vis[1010][1010];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
void dfs(int val,int y,int x){
	if(vis[y][x]) return;
	if(x<=0||x>m||y<=0||y>n) return;
	vis[y][x] = 1;
	for(int i=0;i<4;i++){
		int xx = dx[i]+x;
		int yy = dy[i]+y;
		if(a[yy][xx]-a[y][x]<=val) dfs(val,yy,xx);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	int s = 0, e = 1e9;
	while(s<e){
		int mid = (s+e)/2;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j] = 0;
		dfs(mid,1,1);
		if(vis[n][m]) e = mid;
		else s = mid + 1;
	}
	printf("%d",s);
}
