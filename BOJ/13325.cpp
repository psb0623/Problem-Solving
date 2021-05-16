#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
	int val;
	int s,e;
	SegmentTree* l;
	SegmentTree* r;
	int init(int* a,int start,int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = min(l->init(a,s,(s+e)/2),r->init(a,(s+e)/2+1,e));
		} else return val = a[s];
	}
	int get(int tarS, int tarE){
		if(e<tarS||tarE<s) return 1e9;
		else if(tarS<=s&&e<=tarE) return val;
		else return min(l->get(tarS,tarE),r->get(tarS,tarE));
	}
};
SegmentTree* st = new SegmentTree;
int n;
int t[2100000];
int a[2100000];
long long ans;
void build(int ind, int d, int val){
	if(d==n){
		a[ind-(1<<d)] = val;
		return;	
	}
	build(ind*2,d+1,val+t[ind*2]);
	build(ind*2+1,d+1,val+t[ind*2+1]);
}
void solve(int s,int e, int offset){
	int k = st->get(s,e)-offset;
	ans += k;
	if(s!=e){
		solve(s,(s+e)/2,offset+k);
		solve((s+e)/2+1,e,offset+k);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=2*((1<<n)-1)+1;i++) {
		scanf("%d",&t[i]);
		ans += t[i];
	}
	//puts("check");
	build(1,0,0);
	int mx = 0;
	for(int i=0;i<(1<<n);i++) mx = max(mx,a[i]);
	for(int i=0;i<(1<<n);i++) a[i] = mx-a[i];
	
	//for(int i=0;i<(1<<n);i++) printf("%d ",a[i]);
	//SegmentTree* st = new SegmentTree;
	st->init(a,0,(1<<n)-1);
	solve(0,(1<<n)-1,0);
	
	printf("%d",ans);
}


