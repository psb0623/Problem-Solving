#include<bits/stdc++.h>

using namespace std;

int n,a[1001],d1[1001],d2[1001];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	d1[0]=1;
	for(int i=1;i<n;i++){
		d1[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]) d1[i] = max(d1[i],d1[j]+1);
		}
	}
	
	d2[n-1]=1;
	for(int i=n-2;i>=0;i--){
		d2[i]=1;
		for(int j=n-1;j>i;j--){
			if(a[i]>a[j]) d2[i] = max(d2[i],d2[j]+1);
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		ans = max(ans,d1[i]+d2[i]-1);
	}
	
	printf("%d",ans);
	
}
