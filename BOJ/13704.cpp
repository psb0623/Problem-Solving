#include<bits/stdc++.h>
using namespace std;

int n,k,sqrtN;
int num[1100000];
int a[100010];
long long now = 0ll;

struct Query{
	int idx;
	int s,e;
	bool operator<(const Query& O) const {
		if(s/sqrtN==O.s/sqrtN) return e < O.e;
		return s < O.s;
	}
};
void add(int x){
	now += num[x^k];
	++num[x];
}
void del(int x){
	--num[x];
	now -= num[x^k];
}
int main(){
	scanf("%d %d",&n,&k);
	n++;
	sqrtN = sqrt(n);
	for(int i=1;i<n;i++) scanf("%d",&a[i]), a[i] ^= a[i-1];
	int m;
	scanf("%d",&m);
	vector<Query> Q;
	Q.resize(m);
	vector<long long> ans;
	for(int i=0;i<m;i++){
		int s,e;
		scanf("%d %d",&s,&e);
		Q[i] = {i,s-1,e};
	}
	ans.resize(m);
	sort(Q.begin(), Q.end());
	int s = Q[0].s, e = Q[0].e;
	for(int i=s;i<=e;i++) add(a[i]);
	ans[Q[0].idx] = now;
	
	for(int i=1;i<m;i++){
		while(Q[i].s < s) s--, add(a[s]);
		while(e < Q[i].e) e++, add(a[e]);
		while(s < Q[i].s) del(a[s]), s++;
		while(Q[i].e < e) del(a[e]), e--;
		ans[Q[i].idx] = now; 
	}
	for(long long x:ans) printf("%lld\n",x);
}
