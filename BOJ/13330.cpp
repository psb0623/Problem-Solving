#include <bits/stdc++.h>
using namespace std;
 
int n,k,l;
int L[10001][10001];
int d[10001];
char S[10002];
 
int main(){
    scanf("%d %d %d",&n,&k,&l);
    scanf("%s",S+1);
    for(int i=n;i>0;i--){
        for(int j=i+1;j<=n;j++){
            if (S[i]==S[j]) L[i][j] = L[i+1][j-1]+1;
            else L[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++) d[i] = 1e9;
    for(int i=0;i<n;i++) {
    	if(d[i]!=1e9){
	        for(int j=i+2;j<=n;j++){
	            int u = L[i+1][j], w = j-i;
	            if (2*u*l>=k*w && d[j]>d[i]+1) d[j] = d[i]+1;
	        }
	    }
    }
    if(d[n]!=1e9) printf("%d",d[n]);
    else printf("0");
}
