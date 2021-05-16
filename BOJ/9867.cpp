#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Data{
	ll oo, ox, xo, xx; // o is possibly x
};
Data f(Data l, Data r){
	Data ret;
	ret.oo = max(l.ox+r.xo, max(l.oo+r.xo, l.ox+r.oo));
	ret.ox = max(l.ox+r.xx, max(l.oo+r.xx, l.ox+r.ox));
	ret.xo = max(l.xx+r.xo, max(l.xo+r.xo, l.xx+r.oo));
	ret.xx = max(l.xx+r.xx, max(l.xo+r.xx, l.xx+r.ox));
	return ret;
}
ll a[50010];
struct SegmentTree{
	Data val;
	int s,e;
	SegmentTree *l, *r;
	Data build(int start, int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			Data L = l->build(s,(s+e)/2);
			Data R = r->build((s+e)/2+1,e);
			return val = f(L,R);
		} else {
			val.xo = val.xx = val.ox = 0ll;
			val.oo = a[s];
			return val;
		}
	}
	Data get(int tarS, int tarE){
		if(e<tarS||tarE<s) {
			Data ret = {0ll,0ll,0ll,0ll};
			return ret;
		} else if(tarS<=s&&e<=tarE) return val;
		else return f(l->get(tarS,tarE), r->get(tarS,tarE));
	}
	void update(int tar, ll diff){
		if(e<tar||tar<s) return;
		else if(tar<=s&&e<=tar) val.oo = diff;
		else {
			l->update(tar,diff);
			r->update(tar,diff);
			val = f(l->val,r->val);
		}
	}
};
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	ll ans = 0ll;
	for(int i=0;i<m;i++) {
		int t;
		ll v;
		scanf("%d %lld",&t,&v);
		st->update(t-1,v);
		Data res = st->get(0,n-1);
		ans += max(max(res.oo,res.xx),max(res.ox,res.xo));
	}
	printf("%lld",ans);
}
