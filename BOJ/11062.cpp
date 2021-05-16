#include<bits/stdc++.h>
using namespace std;
int d[1010][1010];
int a[1010];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) d[i][i] = (n&1)?a[i]:0;
		for(int j=1;j<n;j++){
			for(int i=0;i+j<n;i++){
				if((n-j)&1) d[i][i+j] = max(d[i][i+j-1]+a[i+j], d[i+1][i+j]+a[i]);
				else d[i][i+j] = min(d[i][i+j-1], d[i+1][i+j]);
			}
		}
		printf("%d\n",d[0][n-1]);
	}
}
