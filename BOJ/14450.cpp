#include<bits/stdc++.h>
using namespace std;
int d[21][100010][3];
int a[100010];
int n,k;
int f(char c){
	if(c=='P') return 0;
	if(c=='H') return 1;
	if(c=='S') return 2;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		char t;
		scanf("\n%c",&t);
		a[i] = f(t);
		for(int j=0;j<3;j++) d[0][i][j] = d[0][i-1][j];
		d[0][i][f(t)]++;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			d[i][j][0] = max(d[i][j-1][0],max(d[i-1][j-1][1],d[i-1][j-1][2]))+(a[j]==0?1:0);
			d[i][j][1] = max(d[i][j-1][1],max(d[i-1][j-1][0],d[i-1][j-1][2]))+(a[j]==1?1:0);
			d[i][j][2] = max(d[i][j-1][2],max(d[i-1][j-1][1],d[i-1][j-1][0]))+(a[j]==2?1:0);
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++) ans = max(ans,max(d[i][n][0],max(d[i][n][1],d[i][n][2])));
	printf("%d",ans);
}
