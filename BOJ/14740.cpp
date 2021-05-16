#include<bits/stdc++.h>
using namespace std;
long long a[1000010],b[1000010],sum[1000010];
struct SegmentTree{
	int s,e;
	long long val;
	SegmentTree* l;
	SegmentTree* r;
	long long init(int start,int end){
		s = start;
		e = end;
		if(s!=e){
			l = new SegmentTree;
			r = new SegmentTree;
			return val = min(l->init(s,(s+e)/2), r->init((s+e)/2+1,e));
		} else return val = sum[s];
	}
	long long get(int tarS,int tarE){
		if(tarE<s||e<tarS) return LLONG_MAX;
		else if(s<=tarS&&tarE<=e) return val;
		else return min(l->get(tarS,tarE),r->get(tarS,tarE));
	}
};
int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	for(int i=0;i<n;i++) a[i]-=b[i];
	sum[0] = a[0];
	for(int i=1;i<2*n;i++) sum[i] = sum[i-1] + a[i%n];
	SegmentTree* st = new SegmentTree;
	st->init(0,2*n-1);
	int ans = 0;
	for(int i=0;i<n;i++) ans += st->get(i,i+n-1)-sum[i]>=0;
	printf("%d",ans);
}
