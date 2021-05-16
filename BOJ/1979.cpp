#include<bits/stdc++.h>
using namespace std;
int a[10000010],b[10000010];
int n,k;
int main(){
	//for(int i=1;i<10;i++)for(int j=1;j<10;j++){
	scanf("%d %d",&n,&k);
	//n=i,k=j;
	a[0] = k;
	b[0] = (n*k)%10;
	b[1] = (n*k)/10;
	if(a[0]==b[0]&& b[1]==0) return !printf("%d",a[0]);
	int now = 1;
	while(1){
		a[now] = b[now-1];
		b[now] += a[now]*n;
		b[now+1] = b[now]/10;
		b[now] %= 10;
		/*printf("now : %d\na: ",now);
		for(int i=0;i<=now;i++) printf("%d ",a[i]);
		printf("\nb: ");
		for(int i=0;i<=now;i++) printf("%d ",b[i]);
		printf("\n");*/
		if(a[now]!=0 && b[now]==k && b[now+1]==0) break;
		now++;
		if(now>=10000000) return !printf("0");
		//if(now>=10000000) break;
	}
	for(int i=now;i>=0;i--) printf("%d",a[i]);
	//printf("(%d,%d) : %d\n",n,k,now);
	//}
}
