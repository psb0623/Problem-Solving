#include<bits/stdc++.h>
using namespace std;
int sqrtN;

struct Query{
	int s,e,idx;
	bool operator<(const Query& o) const {
		if(s/sqrtN == o.s/sqrtN) return e < o.e;
		return s/sqrtN < o.s/sqrtN;
	}
};

int st[100010];
int n,k,a[100010];
long long ans=0;

int get(int x){
	int ret = 0;
	while(x > 0){
		ret += st[x];
		x -= (x & -x);
	}
	return ret;
	
}

void update(int x, int diff){
	while(x <= 100000){
		st[x] += diff;
		x += (x & -x);
	}
}

void add(int i){
	ans += get( min(100000, a[i]+k) );
	if(a[i]-k-1>0) ans -= get(a[i]-k-1);
	update(a[i], 1);
}

void del(int i){
	update(a[i],-1);
	ans -= get( min(100000, a[i]+k) );
	if(a[i]-k-1>0) ans += get(a[i]-k-1);
}

long long res[100010];

int main(){
	scanf("%d %d",&n,&k);
	sqrtN = sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	vector<Query> Q(m);
	for(int i=0;i<m;i++){
		int s,e;
		scanf("%d %d",&s,&e);
		Q[i] = {s,e,i};
	}
	sort(Q.begin(),Q.end());
	//for(int i=0;i<m;i++) printf("%d %d %d\n",Q[i].idx,Q[i].s,Q[i].e);
	int s = Q[0].s, e = Q[0].e;
	for(int i=s;i<=e;i++) add(i);
	res[Q[0].idx] = ans;
	for(int i=1;i<m;i++){
		while(Q[i].s<s) add(--s);
		while(e<Q[i].e) add(++e);
		while(s<Q[i].s) del(s++);
		while(Q[i].e<e) del(e--);
		res[Q[i].idx] = ans;
	}
	for(int i=0;i<m;i++) printf("%lld\n",res[i]);
	
}
