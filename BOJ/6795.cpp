#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,s;
	cin>>a>>b>>c>>d>>s;
	int x,y;
	x=y=0;
	for(int i=0;i<s;i++){
		if(i%(a+b)<a) ++x;
		else --x;
		if(i%(c+d)<c) ++y;
		else --y;
		//printf("%d %d\n",x,y);
	}
	if(x==y) printf("Tied");
	else if(x>y) printf("Nikky");
	else printf("Byron");
}
