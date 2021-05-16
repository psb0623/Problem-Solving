#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[100010];
struct SegmentTree{
	int s,e;
	ll val;
	ll mx, mn;
	ll a=1ll,b=0ll; // query: x=a*x+b
	
	SegmentTree *l, *r;
	void f(){
		mx = max(l->mx,r->mx);
		mn = min(l->mn,r->mn);
		val = l->val + r->val;
	}
	void prop(){
		if(a==1ll && b==0ll) return;
		val = a*val + b*(e-s+1);
		mx = a*mx + b;
		mn = a*mn + b;
		if(s^e){
			r->a *= a;
			r->b *= a;
			l->a *= a;
			l->b *= a;
			l->b += b;
			r->b += b;
		}
		a = 1ll; b = 0ll;
	}
	void build(int start, int end){
		s = start;
		e = end;
		if(s^e){
			l = new SegmentTree;
			r = new SegmentTree;
			l->build(s,(s+e)/2); r->build((s+e)/2+1,e);
			f();
		} else mx = mn = val = A[s];
	}
	ll get(int tarS, int tarE){
		prop();
		if(tarE<s||e<tarS) return 0ll;
		else if(tarS<=s&&e<=tarE) return val;
		else return l->get(tarS,tarE) + r->get(tarS,tarE);
	}
	void plus(int tarS, int tarE, ll diff){
		prop();
		if(tarE<s||e<tarS) return;
		else if(tarS<=s&&e<=tarE) b = diff, prop();
		else {
			l->plus(tarS, tarE, diff);
			r->plus(tarS, tarE, diff);
			f();
		}
	}
	void sq(int tarS, int tarE){
		prop();
		if(tarE<s||e<tarS||mx==1) return;
		else if(tarS<=s&&e<=tarE&&((int)sqrt(mx)==(int)sqrt(mn) || mn+1 == mx)) {
			//printf("tag : %d,%d with mx:%d, mn:%d\n",s,e,mx,mn);
			if((int)sqrt(mx) == (int)sqrt(mn)){
				a=0, b=(ll)sqrt(mx);
				prop();
			} else {
				b = -mn + (ll)sqrt(mn);
				prop();
			}
		} else {
			l->sq(tarS, tarE);
			r->sq(tarS, tarE);
			f();
		}
	}
};
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	int m;
	scanf("%d",&m);
	do {
		int t,l,r;
		scanf("%d %d %d",&t,&l,&r);--r;--l;
		if(t==1){
			ll x;
			scanf("%lld",&x);
			st->plus(l,r,x);
		} else if(t==2) {
			st->sq(l,r);
		} else {
			printf("%lld\n",st->get(l,r));
		}
		//printf("res : ");
		//for(int i=0;i<n;i++) printf("%lld ",st->get(i,i));
		//puts("");
		
	} while(--m);
}
