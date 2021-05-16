#include<bits/stdc++.h>
using namespace std;
int n, a[1000010], b[1000010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]), a[i]-=i;
	priority_queue<int> pq;
	pq.push(a[0]);
	int ans = 0;
	for(int i=1;i<n;i++){
		b[i-1] = pq.top();
		if(b[i-1]>a[i]){
			ans += b[i-1]-a[i];
			pq.pop();
			pq.push(a[i]);
		} 
		pq.push(a[i]);
	}
	b[n-1] = pq.top();
	for(int i=n-2;i>=0;i--) b[i] = min(b[i],b[i+1]);
	for(int i=0;i<n;i++) printf("%d\n",b[i]+i); 
	//printf("%d",ans);
}
