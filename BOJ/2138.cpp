#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
int solve(int s,int e){
	int ans = 0;
	int t[100010];
	t[0] = s;
	t[n+1] = e;
	for(int i=1;i<=n;i++) t[i] = a[i];
	for(int i=0;i<n;i++){
		if(t[i]!=b[i]){
			t[i]^=1;
			t[i+1]^=1;
			t[i+2]^=1;
			ans++;
		}
	}
	if(t[n]!=b[n] || t[n+1]!=b[n+1]) return 1e9;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%1d",&b[i]);
	int mn = 1e9;
	for(int i=0;i<4;i++) mn = min(mn,solve(i/2,i%2));
	if(mn == 1e9) printf("-1");
	else printf("%d",mn);
}
