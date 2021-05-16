#include<bits/stdc++.h>
using namespace std;
int G[500010],SA[500010],LCP[500010],tmp[500010];
int d,n;
bool cmp(int i,int j){
	if(G[i]!=G[j]) return G[i]<G[j];
	i+=d;
	j+=d;
	return (i<n&&j<n)?(G[i]<G[j]):(i>j);
}
void buildSA(char* s){
	int n = strlen(s);
	for(int i=0;i<n;i++){
		SA[i] = i;
		G[i] = s[i];
	}
	for(d=1;;d*=2){
		sort(SA,SA+n,cmp);
		//memset(tmp,0,sizeof(int)*n);
		for(int i=1;i<n;i++) tmp[i] = tmp[i-1]+cmp(SA[i-1],SA[i]);
		for(int i=0;i<n;i++) G[SA[i]] = tmp[i];
		if(tmp[n-1]==n-1) break;
	}
}
void buildLCP(char* s){
	buildSA(s);
	int n = strlen(s);
	int k;
	for(int i=0,k=0;i<n;i++,k=max(k-1,0)){
		if(G[i]==n-1) continue;
		for(int j=SA[G[i]+1];s[i+k]==s[j+k];k++);
		LCP[G[i]] = k;
	}
}
int main(){
	char s[500010];
	scanf("%s",s);
	n = strlen(s);
	buildSA(s);
	for(int i=0;i<n;i++) printf("%d\n",SA[i]);
	//printf("\nx ");
	//for(int i=0;i<n-1;i++) printf("%d ",LCP[i]);
}
