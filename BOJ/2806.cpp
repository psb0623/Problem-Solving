#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[1000010];
vector<int> v;
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",c);
	int cnt = 0;
	int now = 1;
	int pc = c[0];
	for(int i=1;i<n;i++){
		if(c[i]!=pc) v.push_back(i);
		pc = c[i];
	}
	if(c[n-1]=='B') v.push_back(n);
	int ans = 0;
	for(int i=0;i<v.size();i++){
		ans++;
		if(i<v.size()-1) if(v[i]+1==v[i+1]){
			c[v[i]] = ((c[v[i]]-'A')^1)+'A';
			i++;
		}
	}
	printf("%d",ans);
}
