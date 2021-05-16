#include<bits/stdc++.h>
using namespace std;
int n,k;
map<string,int> m;
set<int> s[2010];
bool ban[2010];
int main(){
	scanf("%d %d",&n,&k);
	int p = 1;
	for(int i=0;i<k;i++){
		int t1,t2;
		string s1,s2;
		scanf("%d %d",&t1,&t2);
		cin>>s1>>s2;
		if(!m[s1]) m[s1] = p++;
		if(!m[s2]) m[s2] = p++;
		s[m[s1]].insert(t1);
		s[m[s2]].insert(t2);
		if(s1==s2) ban[m[s1]] = 1;
	}
	int ans = 0;
	for(int i=1;i<p;i++){
		printf("%d\n",s[i].size());
		if(s[i].size()==2&&!ban[i]) ans++;
	}
	printf("%d",ans);
}
