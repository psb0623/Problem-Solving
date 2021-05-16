#include<bits/stdc++.h>
using namespace std;
map<int,int> rnk;
int n,a[100010],b[100010];
struct SegmentTree{
	int val;
	int s,e;
	SegmentTree* l;
	SegmentTree* r;
	int build(int start,int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = l->build(s,(s+e)/2) + r->build((s+e)/2+1,e);
		} else return val = 0;
	}
	int get(int tarS,int tarE){
		if(tarE<s||e<tarS) return 0;
		else if(tarS<=s&&e<=tarE) return val;
		else return l->get(tarS,tarE) + r->get(tarS,tarE);
	}
	void update(int tar,int diff){
		if(tar<s||e<tar) return;
		else if(tar==s&&tar==e) val = diff;
		else {
			l->update(tar,diff);
			r->update(tar,diff);
			val = l->val + r->val;
		}
	}
};

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b,b+n);
	for(int i=1;i<n;i++) if(b[i]!=b[i-1]) rnk[b[i]] = i;
	SegmentTree* st = new SegmentTree;
	st->build(0,n-1);
	int ans=0;
	for(int i=0;i<n;i++){
		//printf("rank of %d is %d\n",a[i],rnk[a[i]]);
		int l = st->get(rnk[a[i]],n-1);
		int r = n-1-rnk[a[i]] - l;
		//printf("%d %d\n",l,r);
		if(max(l,r)>2*min(l,r)) ans++;
		st->update(rnk[a[i]],1);
	}
	printf("%d",ans);
}
