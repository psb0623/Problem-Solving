#include<bits/stdc++.h>
using namespace std;
int n;
int cur[100010];
int main(){
	scanf("%d",&n);
	int p=0;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		while(t--) cur[p++] = i;
	}
	int k = 0;
	for(int i=0;i<n;i++){
		k = max(cur[i]-i,k);
	}
	long long ans = 0ll;
	for(int i=0;i<n;i++){
		int dest = k+i;
		ans += (dest-cur[i])*(dest-cur[i]);
	}
	printf("%lld",ans);
}
