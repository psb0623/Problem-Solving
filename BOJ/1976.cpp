#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[201][201], d[201][201];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			//if(!a[i][j]) a[i][j] = 1e9;
			d[i][i] = 0;
			d[i][j] = a[i][j]?a[i][j]:1e9;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][k]&&a[k][j]) d[i][j] = min(d[i][j], a[i][k]+a[k][j]);
			}
		}
	}
	int s;
	bool ans=1;
	scanf("%d",&s);
	for(int i=0;i<m-1;i++){
		int e;
		scanf("%d",&e);
		//printf("%d->%d : %d\n",s,e,d[s][e]);
		if(d[s][e]==1e9) ans=0;
	}
	printf("%s",ans?"YES":"NO");
}
