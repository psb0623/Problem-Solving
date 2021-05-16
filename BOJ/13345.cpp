#include<bits/stdc++.h>
using namespace std;
int x[10],y[10];
bool check(int* x, int* y){
	return (x[1]-x[0])*(x[2]-x[0])+(y[1]-y[0])*(y[2]-y[0]);
}
int main(){
	for(int i=0;i<3;i++){
		scanf("%d %d",&x[i],&y[i]);
		x[i+3] = x[i];
		y[i+3] = y[i];
	}
	for(int i=0;i<3;i++) if(!check(x+i,y+i)) printf("%d %d",x[i+1]+x[i+2]-x[i],y[i+1]+y[i+2]-y[i]);
}
