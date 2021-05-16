#include<bits/stdc++.h>
using namespace std;
int n,m;

struct SegmentTree{
	long long val;
	long long lazy=0ll;
	int s,e;
	SegmentTree* left;
	SegmentTree* right;
	
	long long build(int start,int end){
		s = start;
		e = end;
		if(s==e) return val = 0;
		else {
			left = new SegmentTree;
			right = new SegmentTree;
			return val = left->build(s,(s+e)/2) + right->build((s+e)/2+1,e);
		}
	}
	void propagate(){
		if(lazy==0ll) return;
		
		if(s==e) {
			val += lazy;
		} else {
			val += lazy*(e-s+1);
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy=0ll;
	}
	long long get(int tarS, int tarE){
		propagate();
		if(e<tarS||tarE<s) return 0ll;
		else if(tarS<=s&&e<=tarE){
			return val;
		}
		else return left->get(tarS,tarE) + right->get(tarS,tarE);
	}
	void update(int tarS, int tarE, int diff){
		propagate();
		if(e<tarS||tarE<s) return;
		else if(tarS<=s&&e<=tarE){
			lazy += diff;
			propagate();
			return;
		} else {
			left->update(tarS,tarE,diff);
			right->update(tarS,tarE,diff);
			val = left->val + right->val;
		}
	}
};

int last[40010], d[40010] ,a[40010];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	SegmentTree* st = new SegmentTree;
	SegmentTree* st1 = new SegmentTree;
	st->build(0,n-1);
	st1->build(0,n);
	for(int i=0;i<n;i++){
		last[a[i]] = -1;
		d[i] = (i+1);
	}
	d[0] = 1;
	st->update(0,0,1);
	last[a[0]] = 0;
	
	for(int i=1;i<n;i++){
		st->update(last[a[i]]+1,i,1);
		st1->update(1, i-last[a[i]]-1, 1);
		for(int j=1;j*j<=i+1;j++){
			int s = 0, e = i;
			while(s<e){
				int mid = (s+e)/2;
				int x = st->get(mid,mid);
				if( x <= j ) e = mid;
				else s = mid+1;
			}
			//printf("인덱스 : %d, 크기 : %d, 결과 : %d\n",i,j,e);
			int idx = e;
			
			printf("%d %d\n", e, st1->get(j,j)-1);
			
			if(idx == 0){
				d[i] = min(d[i], j*j);
			} else{
				d[i] = min(d[i], d[idx-1] + j*j);
			}
		}
		
		last[a[i]] = i;
	}
	printf("%d",d[n-1]);
}
