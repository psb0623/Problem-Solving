#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Data{
	ll oo, ox, xo, xx; // x is possibly o
};
Data f(Data l, Data r){
	Data ret;
	ret.oo = l.oo + r.oo;
	ret.ox = max(l.ox, l.oo + r.ox);
	ret.xo = max(l.xo + r.oo, r.xo);
	ret.xx = max(l.xo + r.ox, max(l.xx, r.xx));
	return ret;
}
struct SegmentTree{
	Data val;
	int s,e;
	SegmentTree *l=nullptr, *r=nullptr;
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
			val.xo = val.xx = val.ox = val.oo = 0ll;
			return val;
		}
	}
	void init(){
		val.xo = val.xx = val.ox = val.oo = 0ll;
		if(l) l->init();
		if(r) r->init();
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
		else if(tar<=s&&e<=tar) {
			val.oo += diff;
			val.ox = val.xo = val.xx = max(val.oo,0ll);
		} else {
			l->update(tar,diff);
			r->update(tar,diff);
			val = f(l->val,r->val);
		}
	}
};
int n,m;
pair< pair<int,int>, ll > p[3010];
vector<int> xs;
map<int, int> X;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %lld",&p[i].first.second, &p[i].first.first, &p[i].second), xs.push_back(p[i].first.second);
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	for(int i=0;i<xs.size();i++) X[xs[i]] = i;
	sort(p+1,p+n+1);
	p[0] = p[n+1] = {{-1,-1},-1};
	ll ans = 0ll;
	
	SegmentTree* st = new SegmentTree;
	st->build(0,xs.size()-1);
	
	for(int i=1;i<=n;i++){
		if(p[i].first.first == p[i-1].first.first) continue;
		st->init();
		for(int j=i;j<=n;j++){
			//printf("%d,%d\n",p[j].first.second, p[j].first.first);
			st->update(X[p[j].first.second], p[j].second);
			if(p[j].first.first != p[j+1].first.first) {
				Data res = st->get(0,xs.size()-1);
				ans = max(ans, max(max(res.oo,res.ox),max(res.xo,res.xx)));
			}
		}
	}
	printf("%lld",ans);
}
