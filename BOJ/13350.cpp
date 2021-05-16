#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > v;
int d[3000];
int sum = 0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int val,c,f,u;
		scanf("%d %d %d %d",&val,&c,&f,&u);
		sum += val;
		int need = (c+f+u)/2 - c + 1;
		if(need<=u) v.push_back({val,max(need,0)});
	}
	for(int i=1;i<=sum;i++) d[i] = 1e9 + 10;
	sort(v.begin(),v.end());
	int ans = 1e9 + 10;
	for(auto x:v){
		for(int i=sum;i>=x.first;i--){
			d[i] = min(d[i],d[i-x.first] + x.second);
		}
	}
	for(int i=1;i<=sum;i++) {
		if(i>sum/2) ans = min(ans,d[i]);
	}
	if(ans == 1e9 + 10) printf("impossible");
	else printf("%d",ans);
}
