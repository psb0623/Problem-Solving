#include<bits/stdc++.h>
using namespace std;
long long d[1010]={0,1,4,12,};
int main(){
	int n;
	scanf("%d",&n);
	for(int i=4;i<=n;i++){
		d[i]=4*d[i-1]-3*d[i-2]+2*d[i-3]+d[i-4]+4*1000000009ll;
		d[i]%=1000000009;
	}
	printf("%lld",d[n]);
}
