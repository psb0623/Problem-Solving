#include<bits/stdc++.h>
using namespace std;
int n, a[2010];
long long f(int c){
	priority_queue<int> pq;
	pq.push(c*a[0]);
	long long res = 0;
	for(int i=1;i<n;i++){
		int opt = pq.top();
		if(opt>c*a[i]){
			res += opt-c*a[i];
			pq.pop();
			pq.push(c*a[i]);
		} 
		pq.push(c*a[i]);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("%lld",min(f(1),f(-1)));
}
