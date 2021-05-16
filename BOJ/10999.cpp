#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree{
	ll val;
	ll lazy = 0ll;
	int s,e;
	SegmentTree *l,*r;
	ll build(int start, int end, ll* a){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = (l->build(s,(s+e)/2,a) + r->build((s+e)/2+1,e,a));
		} else return val = a[s];
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

ll a[1000010];
int n,m,k;

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1,a);
	
	for(int i=0;i<m+k;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int s,e;
			long long diff;
			scanf("%d %d %lld",&s,&e,&diff);
			--s; --e;
			st->update(s,e,diff);
		} else {
			int s,e;
			scanf("%d %d",&s,&e);
			--s; --e;
			printf("%lld\n",st->get(s,e));
		}
	}
}
