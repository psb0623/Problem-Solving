#include<bits/stdc++.h>
using namespace std;
char s[100010];
int f[100010],d[100010],n,i;
void g(int j, int cnt){
	if(!j){
		cout << cnt << "\n";
		return;
	}
	g(f[j], cnt+1);
	cout << j << " " << d[j]+1 << "\n";
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for(i=1;s[i];i++){
		int j = f[i-1];
		while(j && s[j]!=s[i]) j = f[j];
		f[i] = (j+=s[j]==s[i]); 
		d[j]++;
	}
	for(n=i--;i>0;i--) d[f[i]] += d[i]; 
	g(n, 0);
}
