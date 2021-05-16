#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[60][60];
int vis[60][60];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool f(int k, int x, int y, int px, int py){
	if(x<=0 || y<=0 || x>m || y>n) return 0;
	if(a[y][x] != k) return 0;
	
	if(vis[y][x]) return 1;
	vis[y][x] = 1;
	
	bool res = 0;
	for(int i=0;i<4;i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(xx == px && yy == py) continue;
		res |= f(k,xx,yy,x,y);
	}
	return res;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		char s[100];
		scanf("%s",s);
		for(int j=1;j<=m;j++) a[i][j] = s[j-1]-'A';
	}
	bool ans = 0;
	for(int k=0;k<26;k++){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vis[i][j]) ans |= f(k,j,i,-1,-1);
	}
	printf("%s",ans?"Yes":"No");
}
