#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct SegmentTree{
	long long val = 0;
	long long lazy1 = 1;
	long long lazy2 = 0;
	int s,e;
	SegmentTree *l, *r;
	
	long long build(int start, int end, long long* a){
		s = start;
		e = end;
		if(s!=e) {
			l = new SegmentTree;
			r = new SegmentTree;
			return val = (l->build(s,(s+e)/2, a) + r->build((s+e)/2+1, e, a))%MOD;
		} else return val = a[s];
	}
	
	void propagate(){
		if(lazy1 == 1ll && lazy2 == 0ll) return;
		
		val = lazy1 * val + lazy2*(e-s+1);
		val %= MOD;
		
		if(s!=e){
			l->lazy1 *= lazy1;
			r->lazy1 *= lazy1;
			l->lazy2 *= lazy1;
			r->lazy2 *= lazy1;
			
			l->lazy2 += lazy2;
			r->lazy2 += lazy2;
			
			l->lazy1 %= MOD;
			r->lazy1 %= MOD;
			l->lazy2 %= MOD;
			r->lazy2 %= MOD;
		}
		
		lazy1 = 1ll;
		lazy2 = 0ll;
	}
	
	long long get(int tarS, int tarE){
		propagate();
		if(tarE<s || e<tarS) return 0ll;
		else if(tarS<=s && e<= tarE){	
 			return val;
		} else {
			return (l->get(tarS,tarE) + r->get(tarS,tarE))%MOD;
		}
	}
	
	void plus(int tarS, int tarE, long long v){
		propagate();
		if(tarE<s || e<tarS) return;
		else if(tarS<=s && e<= tarE){	
			lazy2 = v;
			propagate();
		} else {
			l->plus(tarS,tarE, v);
			r->plus(tarS,tarE, v);
			val = l->val + r->val;
			val %= MOD;
		}
	}
	
	void multiply(int tarS, int tarE, long long v){
		propagate();
		if(tarE<s || e<tarS) return;
		else if(tarS<=s && e<= tarE){	
			lazy1 = v;
			propagate();
		} else {
			l->multiply(tarS,tarE, v);
			r->multiply(tarS,tarE, v);
			val = l->val + r->val;
			val %= MOD;
		}
	}
};
int n;
long long a[100010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1, a);
	
	int m;
	scanf("%d",&m);
	
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			long long v;
			scanf("%d %d %lld",&x,&y,&v);
			st->plus(x-1,y-1, v);
		} else if(t==2){
			int x,y;
			long long v;
			scanf("%d %d %lld",&x,&y,&v);
			st->multiply(x-1,y-1, v);
		} else if(t==3){
			int x,y;
			long long v;
			scanf("%d %d %lld",&x,&y,&v);
			st->multiply(x-1,y-1, 0);
			st->plus(x-1,y-1, v);
		} else {
			int x,y;
			scanf("%d %d",&x,&y);
			printf("%lld\n",st->get(x-1,y-1));
		}
		
		//printf("list : ");
		//for(int i=0;i<n;i++) printf("%lld ", st->get(i,i));
		
		//printf("\n");
	}
}
