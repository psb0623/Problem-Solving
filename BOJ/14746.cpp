#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010];
int offset;
int main(){
	scanf("%d %d",&n,&m);
	int t1,t2;
	scanf("%d %d",&t1,&t2);
	offset = abs(t1-t2);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	int x=0,y=0;
	int ans = 1e9;
	while(x<n&&y<m){
		//printf("%d %d\n",a[x],b[y]);
		ans = min(ans,abs(a[x]-b[y]));
		if(a[x]>b[y]) y++;
		else x++;
	}
	x=0,y=0;
	int cnt =0;
	while(x<n&&y<m){
		if(abs(a[x]-b[y])==ans) cnt++;
		if(a[x]>b[y]) y++;
		else x++;
	}
	printf("%d %d",ans+offset,cnt);
}


