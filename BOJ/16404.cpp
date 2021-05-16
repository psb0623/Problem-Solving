#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree{
	ll val;
	ll lazy = 0ll;
	int s,e;
	SegmentTree *l,*r;
	ll build(int start, int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = (l->build(s,(s+e)/2) + r->build((s+e)/2+1,e));
		} else return val = 0ll;
	}
	void propagate(){
		if(lazy==0ll) return;
		val += (e-s+1)*lazy;
		if(s!=e){
			l->lazy += lazy;
			r->lazy += lazy;
		}
		lazy = 0ll;
	}
	ll get(int tarS, int tarE){
		propagate();
		if(tarE<s||e<tarS) return 0ll;
		else if(tarS<=s&&e<=tarE) return val;
		else return l->get(tarS,tarE) + r->get(tarS,tarE);
	}
	void update(int tarS, int tarE, ll diff){
		propagate();
		if(tarE<s||e<tarS) return;
		else if(tarS<=s&&e<=tarE){
			lazy = diff;
			propagate();
		}
		else {
			l->update(tarS, tarE, diff);
			r->update(tarS, tarE, diff);
			val = l->val + r->val;
		}
	}
};

vector<int> child[100010];
int dcnt=0;
int num[100010];
int to[100010];

int dfs(int cur){
	num[cur] = dcnt++;
	if(child[cur].empty()) to[num[cur]] = num[cur];
	for(int next:child[cur]) to[num[cur]] = max(to[num[cur]], dfs(next));
	return to[num[cur]];
}
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(!i) continue;
		child[t-1].push_back(i);
	}
	dfs(0);
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			ll w;
			scanf("%d %lld",&x,&w);
			--x;
			st->update(num[x],to[num[x]],w);
		} else {
			int x;
			scanf("%d",&x);
			--x;
			x = num[x];
			printf("%lld\n",st->get(x,x));
		}
	}
}
