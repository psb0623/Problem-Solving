#include<bits/stdc++.h>
using namespace std;
int n,k,now;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		now += t;
		if(now>k) return !printf("%d",i);
	}
	printf("%d",n);
}
