#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010];
struct SegmentTree{
	int s,e;
	ll val;
	SegmentTree *l, *r;
	ll build(int start, int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = (l->build(s,(s+e)/2) + r->build((s+e)/2+1,e));
		} else return val = a[s];
	}
	ll get(int tarS, int tarE){
		if(tarE<s || e<tarS) return 0ll;
		else if(tarS<=s && e<=tarE) return val;
		else return l->get(tarS,tarE) + r->get(tarS,tarE);
	}
	void update(int tar, long long diff){
		if(tar<s || e<tar) return;
		else if(tar==s && tar==e) val = diff;
		else{
			l->update(tar,diff);
			r->update(tar,diff);
			val = l->val + r->val;
		}
	}
};
int n,m;
vector< pair< int, ll> > q1;
vector< pair< int, pair<int,int> > > q2[100010];
	
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	

	scanf("%d",&m);
	int p = 0;
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int tar, diff;
			scanf("%d %d",&tar,&diff);
			q1.push_back({tar,diff});
		} else {
			int k,x,y;
			scanf("%d %d %d",&k,&x,&y);
			q2[k].push_back({p++,{x,y}});
		}
	}
	vector<long long> ans;
	ans.resize(p);
	for(int i=0;i<=q1.size();i++){
		for(auto x:q2[i]){
			int idx = x.first;
			int s = x.second.first;
			int e = x.second.second;
			ans[idx] = st->get(s-1,e-1);
		}
		if(i<q1.size()){
			int tar = q1[i].first;
			long long diff = q1[i].second;
			st->update(tar-1,diff);
		}
	}
	for(int i=0;i<p;i++) printf("%lld\n",ans[i]);
}
