#include<bits/stdc++.h>
using namespace std;
int n,l,w,a[1010];
int b[1010];
int cnt, cur, t;
int main(){
	scanf("%d %d %d",&n,&l,&w);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	while(cnt!=n||cur!=0){
		for(int i=l;i>=1;i--) b[i+1] = b[i];
		b[1] = 0;
		cur -= b[l+1];
		b[l+1] = 0;
		if(cur+a[cnt]<=w&&cnt<n) {
			cur += a[cnt];
			b[1] = a[cnt];
			cnt++;
		}
		t++;
	}
	printf("%d",t);
}
