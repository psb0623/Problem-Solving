#include<bits/stdc++.h>
using namespace std;
int n,a[30],b[30];
bool check(int k){
	for(int i=1;i<=k;i++) for(int j=i;j<n;j+=k) if(b[j]!=b[i]) return 0;
	return 1;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0) return 0;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		for(int i=1;i<n;i++) b[i] = a[i] - a[i-1];
		for(int i=1;i<n;i++) if(check(i)){
			printf("%d\n",i);
			break;
		}
	}
	
}
