#include<bits/stdc++.h>
using namespace std;
int n,a[2020],d[2020][2020];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	d[1][0] = 0;
	d[0][1] = 0;
	for(int i=2;i<=n;i++){
		
		// left is on top
		// (i-1,j)
		
		d[i-1][i] = d[i-1][0];
		d[i][i-1] = d[0][i-1];
		d[i][0] = d[i-1][0] + abs(a[i]-a[i-1]);
		d[0][i] = d[0][i-1] + abs(a[i]-a[i-1]);
		
		for(int j=1;j<i-1;j++){
			// left is on top : (i-1,j)
			d[i-1][i] = min(d[i-1][i], d[i-1][j] + abs(a[i]-a[j])); // move right
			d[i][j] = d[i-1][j] + abs(a[i]-a[i-1]); // move left 
			// right is on top : (j, i-1)
			d[j][i] = d[j][i-1] + abs(a[i]-a[i-1]); // move right
			d[i][i-1] = min(d[i-1][i], d[j][i-1] + abs(a[i]-a[j])); // move left;
		}
	}
	int ans = 1e9;
	for(int i=0;i<n;i++){
		//printf("%d %d\n",d[i][n],d[n][i]);
		ans = min(ans, d[n][i]);
		ans = min(ans, d[i][n]);
	} 
	printf("%d",ans);
}
