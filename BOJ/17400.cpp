#include<bits/stdc++.h>
using namespace std;
long long a[300010];
struct SegmentTree{
	long long val;
	int s,e;
	SegmentTree* l;
	SegmentTree* r;
	long long build(int start,int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = l->build(s,(s+e)/2) + r->build((s+e)/2+1,e);
		} else return val = a[s];
	}
	long long get(int tarS, int tarE){
		if(e<tarS||tarE<s) return 0ll;
		else if(tarS<=s&&e<=tarE) return val;
		else {
			return l->get(tarS,tarE) + r->get(tarS,tarE);	
		}
	}
	void update(int tar,long long diff){
		if(e<tar||tar<s) return;
		else if(tar==s&&tar==e) val += diff;
		else {
			l->update(tar,diff);
			r->update(tar,diff);
			val = l->val + r->val;
		}
	}
};
int n,q;
int main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(i%2) a[i]*=-1ll;
	}
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	for(int i=0;i<q;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			r--;
			printf("%lld\n",abs(st->get(l,r)));
		} else {
			int tar;
			long long diff;
			scanf("%d %lld",&tar,&diff);
			if((tar-1)%2) diff *= -1;
			st->update(tar-1,diff);
		}
	}
}
