#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
	int s,e;
	int val;
	int lazy = 0;
	SegmentTree *l,*r;
	int init(int *a, int start, int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = (l->init(a,s,(s+e)/2))^(r->init(a,(s+e)/2+1,e));
		} else return val = a[s];
	}
	void propagate(){
		if(lazy==0ll) return;
		if(s==e) {
			val ^= lazy;
		} else {
			if((e-s+1)%2) val ^= lazy;
			l->lazy ^= lazy;
			r->lazy ^= lazy;
		}
		lazy=0ll;
	}
	int get(int tarS, int tarE){
		propagate();
		if(e<tarS||tarE<s) return 0;
		else if(tarS<=s&&e<=tarE) return val;
		else return (l->get(tarS,tarE))^(r->get(tarS,tarE));
	}
	void update(int tarS, int tarE, int diff){
		propagate();
		if(e<tarS||tarE<s) return;
		else if(tarS<=s&&e<=tarE){
			lazy ^= diff;
			propagate();
			return;
		} else {
			l->update(tarS,tarE,diff);
			r->update(tarS,tarE,diff);
			val = l->val^r->val;
		}
	}
};
int n,a[500010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	SegmentTree* st = new SegmentTree;
	st->init(a,0,n-1);
	int m;
	scanf("%d",&m);
	while(m--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int s,e,diff;
			scanf("%d %d %d",&s,&e,&diff);
			st->update(s,e,diff);
		} else {
			int tar;
			scanf("%d",&tar);
			printf("%d\n",st->get(tar,tar));
		}
	}
}
