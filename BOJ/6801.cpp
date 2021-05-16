#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[2010];
int go(int c,int l){
	int i=0;
	int p=0;
	int ans = 0;
	while(i<n){
		while(a[i+c] <= a[p+c]+l && i<n) i++;
		p=i;
		ans++;
	}
	return ans;
}
int f(int l){
	int ret = 1e9;
	for(int i=0;i<n;i++) ret = min(ret,go(i,l));
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++) a[i+n] = a[i]+1e6;
	int s = 0, e = 1e6;
	scanf("%d",&k);
	while(s<e) {
		int mid = (s+e)/2;
		//printf("%d\n",mid);
		if(f(mid)<=k) e = mid;
		else s = mid+1;
	}
	if(e%2) printf("%d",e/2+1);
	else printf("%d",e/2);
}
