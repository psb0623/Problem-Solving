#include<bits/stdc++.h>
using namespace std;
int n, a[51], d[51][500001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	d[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=500000;j++){
			int high = d[i-1][j];
			int low = high - j;
			if(!high) continue;
			d[i][j] = max(d[i][j],high);
			d[i][j+a[i]] = max(d[i][j+a[i]], high+a[i]);
			d[i][abs(j-a[i])] = max(d[i][abs(j-a[i])], max(high, low+a[i]) );
		}
	}
	
	if(d[n][0]==1) d[n][0] = 0;
	printf("%d", d[n][0]-1);
}
