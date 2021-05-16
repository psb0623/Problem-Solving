#include<bits/stdc++.h>
using namespace std;
int n, d[2000020];
bool vis[2000020];
pair<int,int> p[1000020];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		p[i] = {t2, t1};
	}
	sort(p,p+n);
	int A = 0;
	int B = 0;
	int ans = 0;
	d[1000005] = -1;
	vis[1000005] = 1;
	
	for(int i=0;i<n;i++){
		//printf("%d : %d %d\n",i, p[i].second, p[i].first);
		
		if(p[i].second) A++;
		else B++;
		
		int idx = 1e6+A-B+5;
		
		
		if(!vis[idx]){
			vis[idx] = 1;
			d[idx] = i;
		} else {
			ans = max(ans, p[i].first - p[d[idx]+1].first);
			//printf("%d~%d\n",i,d[idx]+1);
		}
	}
	printf("%d",ans);
}
