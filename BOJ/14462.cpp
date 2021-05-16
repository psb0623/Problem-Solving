#include<bits/stdc++.h>
using namespace std;
int d[1001][1001];
int a[1001],b[1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		d[i][j] = max(d[i][j-1],d[i-1][j]);
		if(abs(a[i]-b[j])<=4) d[i][j] = max(d[i][j],d[i-1][j-1]+1);
	}
	printf("%d",d[n][n]);
}
