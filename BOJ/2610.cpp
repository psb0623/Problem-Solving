#include<bits/stdc++.h>
using namespace std;
int d[110][110];
bool vis[110];
int ccn = 0;
vector<int> v[110];
vector<int> cc[110];
void f(int cur){
	if(vis[cur]) return;
	vis[cur] = 1;
	cc[ccn].push_back(cur);
	for(int next:v[cur]) f(next);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i-j) d[i][j] = 1e9;
	for(int i=0;i<m;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		t1--;
		t2--;
		d[t1][t2] = d[t2][t1] = 1;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	
	for(int i=0;i<n;i++) if(!vis[i]) {
		f(i);
		ccn++;
	}
	vector<int> ans;
	for(int i=0;i<ccn;i++) {
		int mx = 1e9;
		int res = 0;
		int sum = 0;
		for(int x:cc[i]) {
			sum = 0;
			for(int y:cc[i]) sum = max(sum,d[x][y]);
			if(sum < mx){
				mx = sum;
				res = x;
			}
		}
		ans.push_back(res);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n",ccn);
	for(int x:ans) printf("%d\n",x+1);
}
